//
//  Wrapper.h
//  SwiftPlusCPP
//
//  Created by Radar on 2018/6/15.
//  Copyright © 2018年 radar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Wrapper: NSObject

- (NSString *)markdownToJson:(NSString *)json;
- (NSString *)jsonToMarkdown:(NSString *)json;

@end
