//
//  ConverterWrapper.swift
//  SwiftPlusCPP
//
//  Created by Radar on 2018/6/26.
//  Copyright © 2018年 radar. All rights reserved.
//

import Foundation

class ConverterWrapper {
    static func markdownToJson(_ markdown: String) -> String {
        return Wrapper().markdown(toJson: markdown)
    }

    static func jsonToMarkdown(_ json: String) -> String {
        return Wrapper().json(toMarkdown: json)
    }
}
