//
//  Theme.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-10-06.
//  Copyright © 2019 Zamzam Inc. All rights reserved.
//

#if canImport(UIKit)
import UIKit
#elseif canImport(AppKit)
import AppKit
public typealias UIColor = NSColor
#endif

public protocol Theme {
    var tint: UIColor { get }
    var secondaryTint: UIColor { get }
    
    var backgroundColor: UIColor { get }
    var secondaryBackgroundColor: UIColor { get }
    var tertiaryBackgroundColor: UIColor { get }
    var quaternaryBackgroundColor: UIColor { get }
    
    var separatorColor: UIColor { get }
    var opaqueColor: UIColor { get }
    
    var labelColor: UIColor { get }
    var secondaryLabelColor: UIColor { get }
    var tertiaryLabelColor: UIColor { get }
    var quaternaryLabelColor: UIColor { get }
    var placeholderLabelColor: UIColor { get }
    
    var buttonCornerRadius: CGFloat { get }
    
    var positiveColor: UIColor { get }
    var negativeColor: UIColor { get }
    
    var isDarkStyle: Bool { get }
}
