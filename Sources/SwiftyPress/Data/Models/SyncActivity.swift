//
//  SyncActivity.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-10-17.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

import Foundation.NSDate
import RealmSwift

@objcMembers
class SyncActivity: Object {
    dynamic var type: String = ""
    dynamic var lastFetchedAt: Date?
    
    override static func primaryKey() -> String? {
        "type"
    }
}
