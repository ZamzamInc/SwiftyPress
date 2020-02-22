//
//  HTTPService.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-17.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

import Foundation
import Alamofire

public protocol HTTPServiceType {
    func get(url: String, parameters: [String: Any], headers: [String: String]?, completion: @escaping (Result<NetworkAPI.Response, NetworkAPI.Error>) -> Void)
    func post(url: String, parameters: [String: Any], headers: [String: String]?, completion: @escaping (Result<NetworkAPI.Response, NetworkAPI.Error>) -> Void)
}

public struct HTTPService: HTTPServiceType {
    private let session: Session
    
    init() {
        self.session = .init(configuration: .default)
    }
}

public extension HTTPService {
    
    func get(url: String, parameters: [String: Any], headers: [String: String]? = nil, completion: @escaping (Result<NetworkAPI.Response, NetworkAPI.Error>) -> Void) {
        guard let url = URL(string: url) else {
            completion(.failure(NetworkAPI.Error(statusCode: 400)))
            return
        }
        
        var urlRequest = URLRequest(url: url)
        urlRequest.httpMethod = HTTPMethod.get.rawValue
        
        do {
            urlRequest = try URLEncoding.default.encode(urlRequest, with: parameters)
        } catch {
            completion(.failure(
                NetworkAPI.Error(urlRequest: urlRequest, statusCode: 0, internalError: error)
            ))
            
            return
        }
        
        headers?.forEach {
            urlRequest.setValue($0.value, forHTTPHeaderField: $0.key)
        }
        
        session.request(urlRequest, completion: completion)
    }
}

public extension HTTPService {
    
    func post(url: String, parameters: [String: Any], headers: [String: String]? = nil, completion: @escaping (Result<NetworkAPI.Response, NetworkAPI.Error>) -> Void) {
        guard let url = URL(string: url) else {
            completion(.failure(NetworkAPI.Error(statusCode: 400)))
            return
        }
        
        var urlRequest = URLRequest(url: url)
        urlRequest.httpMethod = HTTPMethod.post.rawValue
        
        do {
            urlRequest = try JSONEncoding.default.encode(urlRequest, with: parameters)
        } catch {
            completion(.failure(
                NetworkAPI.Error(urlRequest: urlRequest, statusCode: 0, internalError: error)
            ))
            
            return
        }
        
        headers?.forEach {
            urlRequest.setValue($0.value, forHTTPHeaderField: $0.key)
        }
        
        session.request(urlRequest, completion: completion)
    }
}

// MARK: - HTTP library helper

public extension Session {
    
    /// Creates a network request to retrieve the contents of a URL based on the specified urlRequest.
    ///
    /// - Parameters:
    ///   - urlRequest: The URL request.
    ///   - completion: A handler to be called once the request has finished.
    func request(_ urlRequest: URLRequest, completion: @escaping (Result<NetworkAPI.Response, NetworkAPI.Error>) -> Void) {
        request(urlRequest)
            .validate()
            .responseData {
                let statusCode = $0.response?.statusCode ?? 0
                let headers: [String: String] = {
                    guard let allHeaderFields = $0 else { return [:] }
                    return Dictionary(uniqueKeysWithValues: allHeaderFields.map {("\($0)", "\($1)")})
                }($0.response?.allHeaderFields)
                
                // Handle errors
                guard case .success(let value) = $0.result else {
                    let error = NetworkAPI.Error(
                        urlRequest: $0.request,
                        statusCode: statusCode,
                        headerValues: headers,
                        serverData: $0.data,
                        internalError: $0.error
                    )
                    
                    completion(.failure(error))
                    return
                }
                
                completion(.success(
                    NetworkAPI.Response(
                        data: value,
                        headers: headers,
                        statusCode: statusCode)
                    )
                )
        }
    }
}

