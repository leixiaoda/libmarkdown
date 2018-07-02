//
//  paragraph.hpp
//  MarkdownParser
//
//

#ifndef paragraph_hpp
#define paragraph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "../json.h"
#include "Markup.hpp"

using nlohmann::json;

namespace Sunrise {
    struct Paragraph {
        std::string id;
        std::string text;
        int type;
        int index;
        std::vector<Sunrise::Markup> markups;
        std::string url;
    };
    void to_json(json& j, const Paragraph& p);
    void from_json(const json& j, Paragraph& p);

    std::string getBlockTypeString(int type);
}
#endif /* paragraph_hpp */
