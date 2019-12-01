//
//  MediaStoreInterfaces.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-04.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

/// Media request namespace
public enum MediaAPI {}

public protocol MediaStore {
    func fetch(id: Int, completion: @escaping (Result<MediaType, DataError>) -> Void)
    func fetch(ids: Set<Int>, completion: @escaping (Result<[MediaType], DataError>) -> Void)
    func createOrUpdate(_ request: MediaType, completion: @escaping (Result<MediaType, DataError>) -> Void)
}

public protocol MediaRemote {
    func fetch(id: Int, completion: @escaping (Result<MediaType, DataError>) -> Void)
}

public protocol MediaProviderType {
    func fetch(id: Int, completion: @escaping (Result<MediaType, DataError>) -> Void)
    func fetch(ids: Set<Int>, completion: @escaping (Result<[MediaType], DataError>) -> Void)
}
