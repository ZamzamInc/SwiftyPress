//
//  AuthorsMemoryStore.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-04.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

public struct AuthorFileStore: AuthorStore {
    private let seedStore: SeedStore
    
    init(seedStore: SeedStore) {
        self.seedStore = seedStore
    }
}

public extension AuthorFileStore {
    
    func fetch(id: Int, completion: @escaping (Result<AuthorType, DataError>) -> Void) {
        seedStore.fetch {
            guard case .success(let value) = $0 else {
                completion(.failure($0.error ?? .unknownReason(nil)))
                return
            }
            
            // Find match
            guard let model = value.authors.first(where: { $0.id == id }) else {
                completion(.failure(.nonExistent))
                return
            }
            
            completion(.success(model))
        }
    }
}

public extension AuthorFileStore {
    
    func createOrUpdate(_ request: AuthorType, completion: @escaping (Result<AuthorType, DataError>) -> Void) {
        // Nothing to do
    }
}
