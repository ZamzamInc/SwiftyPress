//
//  Dictionary.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-17.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

private extension Dictionary {
    
    /// Keys to scrub
    static var scrubKeys: [String] {
        [
            "Authorization",
            "Set-Cookie",
            "user_email",
            "password",
            "first_name",
            "last_name",
            "email",
            "phone_number",
            "profile_picture_url",
            "token"
        ]
    }
    
    static func scrub(value: [AnyHashable: Any]) -> [String: String] {
        [String: String](uniqueKeysWithValues: value.map {
            let key = "\($0)"
            let value = !key.within(scrubKeys) || ($1 as? String)?.isEmpty == true ? "\($1)" : "*****"
            return (key, value)
        })
    }
}

extension Dictionary where Key == AnyHashable, Value == Any {
    
    /// Remove sensitive info from headers
    var scrubbed: [String: String] { Self.scrub(value: self) }
}

extension Dictionary where Key == String, Value == String {
    
    /// Remove sensitive info from headers
    var scrubbed: [String: String] { Self.scrub(value: self) }
}
