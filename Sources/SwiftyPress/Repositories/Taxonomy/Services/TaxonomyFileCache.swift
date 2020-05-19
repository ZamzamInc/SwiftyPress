//
//  TaxonomyFileCache.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-04.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

public struct TaxonomyFileCache: TaxonomyCache {
    private let seedService: DataSeed
    
    init(seedService: DataSeed) {
        self.seedService = seedService
    }
}

public extension TaxonomyFileCache {
    
    func fetch(id: Int, completion: @escaping (Result<Term, SwiftyPressError>) -> Void) {
        fetch {
            // Handle errors
            guard case .success = $0 else {
                completion(.failure($0.error ?? .unknownReason(nil)))
                return
            }
            
            // Find match
            guard case .success(let item) = $0,
                let model = item.first(where: { $0.id == id }) else {
                    completion(.failure(.nonExistent))
                    return
            }
            
            completion(.success(model))
        }
    }
    
    func fetch(slug: String, completion: @escaping (Result<Term, SwiftyPressError>) -> Void) {
        fetch {
            // Handle errors
            guard case .success = $0 else {
                completion(.failure($0.error ?? .unknownReason(nil)))
                return
            }
            
            // Find match
            guard case .success(let item) = $0,
                let model = item.first(where: { $0.slug == slug }) else {
                    completion(.failure(.nonExistent))
                    return
            }
            
            completion(.success(model))
        }
    }
}

public extension TaxonomyFileCache {
    
    func fetch(completion: @escaping (Result<[Term], SwiftyPressError>) -> Void) {
        seedService.fetch {
            guard case .success(let item) = $0 else {
                completion(.failure($0.error ?? .unknownReason(nil)))
                return
            }
            
            completion(.success(item.terms))
        }
    }
}

public extension TaxonomyFileCache {
    
    func fetch(ids: Set<Int>, completion: @escaping (Result<[Term], SwiftyPressError>) -> Void) {
        fetch {
            guard case .success(let items) = $0 else {
                completion($0)
                return
            }
            
            let model = ids.reduce(into: [Term]()) { result, next in
                guard let element = items.first(where: { $0.id == next }) else { return }
                result.append(element)
            }
            
            completion(.success(model))
        }
    }
    
    func fetch(by taxonomy: Taxonomy, completion: @escaping (Result<[Term], SwiftyPressError>) -> Void) {
        fetch {
            guard case .success(let items) = $0 else {
                completion($0)
                return
            }
            
            completion(.success(items.filter { $0.taxonomy == taxonomy }))
        }
    }
    
    func fetch(by taxonomies: [Taxonomy], completion: @escaping (Result<[Term], SwiftyPressError>) -> Void) {
        fetch {
            guard case .success(let items) = $0 else {
                completion($0)
                return
            }
            
            completion(.success(items.filter { taxonomies.contains($0.taxonomy) }))
        }
    }
}

public extension TaxonomyFileCache {
    
    func getID(bySlug slug: String) -> Int? {
        fatalError("Not implemented")
    }
}
