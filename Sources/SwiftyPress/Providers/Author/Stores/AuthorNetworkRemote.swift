//
//  AuthorNetworkRemote.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2019-05-17.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

import Foundation
import ZamzamCore

public struct AuthorNetworkRemote: AuthorRemote {
    private let apiSession: APISessionType
    private let jsonDecoder: JSONDecoder
    private let log: LogProviderType
    
    public init(apiSession: APISessionType, jsonDecoder: JSONDecoder, log: LogProviderType) {
        self.apiSession = apiSession
        self.jsonDecoder = jsonDecoder
        self.log = log
    }
}

public extension AuthorNetworkRemote {
    
    func fetch(id: Int, completion: @escaping (Result<AuthorType, DataError>) -> Void) {
        apiSession.request(APIRouter.readAuthor(id: id)) {
            // Handle errors
            guard case .success = $0 else {
                // Handle no existing data
                if $0.error?.statusCode == 404 {
                    completion(.failure(.nonExistent))
                    return
                }
                
                self.log.error("An error occured while fetching the author: \(String(describing: $0.error)).")
                completion(.failure(DataError(from: $0.error)))
                return
            }
            
            // Ensure available
            guard case .success(let value) = $0 else {
                completion(.failure(.nonExistent))
                return
            }
            
            DispatchQueue.transform.async {
                do {
                    // Type used for decoding the server payload
                    struct ServerResponse: Decodable {
                        let author: Author
                    }
                    
                    // Parse response data
                    let payload = try self.jsonDecoder.decode(ServerResponse.self, from: value.data)
                    
                    DispatchQueue.main.async {
                        completion(.success(payload.author))
                    }
                } catch {
                    self.log.error("An error occured while parsing the author: \(error).")
                    DispatchQueue.main.async { completion(.failure(.parseFailure(error))) }
                    return
                }
            }
        }
    }
}
