//
//  PreferencesStoreInterfaces.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-10-06.
//

import ZamzamKit

public protocol PreferencesStore {
    func get<T>(_ key: UserDefaults.Key<T?>) -> T?
    func set<T>(_ value: T?, forKey key: UserDefaults.Key<T?>)
    func remove<T>(_ key: UserDefaults.Key<T?>)
}

public protocol PreferencesType: PreferencesStore {
    var userID: Int? { get }
    var favorites: [Int] { get }
    func removeAll()
}
