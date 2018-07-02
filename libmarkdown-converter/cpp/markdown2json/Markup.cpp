
#include "Markup.hpp"

using Sunrise::Markup;

std::string Sunrise::getMarkupTypeString(int type) {
    std::string ret = "";
    switch (type) {
        case ITALIC:
            ret = "italic";
            break;
        case BOLD:
            ret = "strong";
            break;
        case LINK:
            ret = "link";
            break;
        case CODE:
            ret = "inlineCode";
            break;
        case UNDERLINE:
            ret = "underline";
            break;
        case STRIKE_THROUGH:
            ret = "strikethrough";
            break;
    }
    return ret;
}

void Sunrise::to_json(json& j, const Markup& m) {
    j = json{
        {"start", m.start},
        {"end", m.end},
        {"style", getMarkupTypeString(m.type)},
    };

    // If the markup type is a link
    if (m.type == LINK) {
//        j.emplace("anchorType", m.anchorType);
//        j.emplace("rel", m.rel);
        j.emplace("link", m.href);
//        j.emplace("title", m.title);
    }

}

void Sunrise::from_json(const json& j, Markup& m) {
    m.start = j.at("start").get<int>();
    m.end = j.at("end").get<int>();
    m.type = j.at("type").get<int>();

    if (m.type == LINK) {
        m.anchorType = j.at("anchorType").get<int>();
        m.rel = j.at("rel").get<std::string>();
        m.href = j.at("href").get<std::string>();
        m.title = j.at("title").get<std::string>();
    }
}