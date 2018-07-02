//
//  paragraph.cpp
//  MarkdownParser
//
//

#include "BlockType.hpp"
#include "Paragraph.hpp"

using Sunrise::Paragraph;

std::string Sunrise::getBlockTypeString(int type) {
    std::string ret = "";
    switch (type) {
        case doc:
            ret = "doc";
            break;
        case h1:
            ret = "h1";
            break;
        case h2:
            ret = "h2";
            break;
        case h3:
            ret = "h3";
            break;
        case paragraph:
            ret = "paragraph";
            break;
        case unordered_list:
            ret = "bulletedList";
            break;
        case ordered_list:
            ret = "numberList";
            break;
        case image:
            ret = "image";
            break;
        case block_quote:
            ret = "quote";
            break;

    }
    return ret;
}

void Sunrise::to_json(json& j, const Paragraph& p) {
    std::string typeStr = getBlockTypeString(p.type);
    if (p.markups.size() > 0) {
        j = json{
                {"id", p.id},
                {"text", p.text},
                {"type", typeStr},
                {"index", p.index},
                {"styles", p.markups}
        };
    } else {
        if (p.type == image) {
            j = json{
                    {"id", p.id},
                    //{"text", p.text},
                    {"type", typeStr},
                    {"index", p.index},
                    {"uri", p.url}
            };
        } else {
            j = json{
                    {"id", p.id},
                    {"text", p.text},
                    {"type", typeStr},
                    {"index", p.index}
            };
        }
    }
}

void Sunrise::from_json(const json& j, Paragraph& p) {
    p.id = j.at("id").get<std::string>();
    p.text = j.at("text").get<std::string>();
    p.type = j.at("type").get<int>();
    p.markups = j.at("markups").get<std::vector<Sunrise::Markup>>();
}

