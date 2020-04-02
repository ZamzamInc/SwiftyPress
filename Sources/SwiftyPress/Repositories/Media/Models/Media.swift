//
//  Media.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-03.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

public struct Media: MediaType, Identifiable, Decodable {
    public let id: Int
    public let link: String
    public let width: Int
    public let height: Int
    public let thumbnailLink: String
    public let thumbnailWidth: Int
    public let thumbnailHeight: Int
}

// MARK: - Codable

private extension Media {
    
    enum CodingKeys: String, CodingKey {
        case id
        case link
        case width
        case height
        case thumbnailLink = "thumbnail_link"
        case thumbnailWidth = "thumbnail_width"
        case thumbnailHeight = "thumbnail_height"
    }
}

// MARK: - Conversions

extension Media {
    
    /// For converting to one type to another.
    ///
    /// - Parameter object: An instance of media type.
    init(from object: MediaType) {
        self.init(
            id: object.id,
            link: object.link,
            width: object.width,
            height: object.height,
            thumbnailLink: object.thumbnailLink,
            thumbnailWidth: object.thumbnailWidth,
            thumbnailHeight: object.thumbnailHeight
        )
    }
    
    /// For converting to one type to another.
    ///
    /// - Parameter object: An instance of media type.
    init?(from object: MediaType?) {
        guard let object = object else { return nil }
        self.init(from: object)
    }
}
