//
//  WrapperSwift.swift
//  Creation
//
//  Created by bytedance on 2018/6/25.
//  Copyright © 2018年 Bytedance. All rights reserved.
//

import Foundation

public class WrapperSwift {
    static func markdownToJson(_ markdown: String) -> String {
        guard let json = Wrapper().markdown(toJson: markdown) else {
            return ""
        }

        if json.count > 0 {
            print("ok")
        } else {
            print("nope")
        }
        return json
    }
}
