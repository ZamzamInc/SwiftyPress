//
//  SeedNetworkStore.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-10-09.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

import Foundation
import ZamzamCore

public struct RemoteNetworkStore: RemoteStore {
    private let apiSession: APISessionType
    private let jsonDecoder: JSONDecoder
    private let log: LogProviderType
    
    public init(apiSession: APISessionType, jsonDecoder: JSONDecoder, log: LogProviderType) {
        self.apiSession = apiSession
        self.jsonDecoder = jsonDecoder
        self.log = log
    }
}

public extension RemoteNetworkStore {
    
    func configure() {
        // No configure needed
    }
    
    func fetchModified(after date: Date?, with request: DataAPI.ModifiedRequest, completion: @escaping (Result<SeedPayloadType, DataError>) -> Void) {
        apiSession.request(APIRouter.modified(after: date, request)) {
            guard case .success(let value) = $0 else {
                // Handle no modified data and return success
                if $0.error?.statusCode == 304 {
                    completion(.success(SeedPayload()))
                    return
                }
                
                self.log.error("An error occured while fetching the modified payload: \(String(describing: $0.error)).")
                completion(.failure(DataError(from: $0.error)))
                return
            }
            
            DispatchQueue.transform.async {
                do {
                    // Parse response data
                    let payload = try self.jsonDecoder.decode(SeedPayload.self, from: value.data)
                    DispatchQueue.main.async { completion(.success(payload)) }
                } catch {
                    self.log.error("An error occured while parsing the modified payload: \(error).")
                    DispatchQueue.main.async { completion(.failure(.parseFailure(error))) }
                    return
                }
            }
        }
    }
}
