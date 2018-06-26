//
// Created by chenlong.01 on 2018/5/23.
//

#ifndef JSON2MARKDOWNPARSER_HPP
#define JSON2MARKDOWNPARSER_HPP

#include <string>
#include "../json.h"

using namespace nlohmann;

// block types
#define H1             "h1"
#define H2             "h2"
#define H3             "h3"
#define PARAGRAPH      "paragraph"
#define UNORDERED_LIST "bulletedList"
#define ORDERED_LIST   "numberList"
#define IMAGE          "image"
#define QUOTE          "quote"

// paragraph styles
#define STR_ITALIC         "italic"
#define STR_BOLD           "strong"
#define STR_LINK           "link"
#define STR_CODE           "inlineCode"
#define STR_UNDERLINE      "underline"
#define STR_STRIKE_THROUGH "strikethrough"

namespace Sunset
{
    std::string json_to_markdown(std::string json_str);

}

#endif //JSON2MARKDOWNPARSER_HPP
