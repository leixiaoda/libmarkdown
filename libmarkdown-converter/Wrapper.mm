//
//  Wrapper.m
//  SwiftPlusCPP
//
//  Created by Radar on 2018/6/15.
//  Copyright © 2018年 radar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Wrapper.h"
#import "Parser.hpp"
#import "Json2MarkdownParser.hpp"

@implementation Wrapper
- (NSString *)markdownToJson:(NSString *)markdown {
    std::string json = Sunrise::markdown_to_json(std::string([markdown UTF8String]));
    return [NSString stringWithUTF8String:json.c_str()];
}

- (NSString *)jsonToMarkdown:(NSString *)json {
    std::string markdown = Sunrise::json_to_markdown(std::string([json UTF8String]));
    return [NSString stringWithUTF8String:markdown.c_str()];
}

@end
