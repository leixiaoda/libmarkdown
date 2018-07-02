//
// Created by chenlong.01 on 2018/5/24.
//

#ifndef STYLE_HPP
#define STYLE_HPP

#include <string>
#include "../json.h"

using nlohmann::json;

namespace Sunrise
{

    struct Style
    {
        int start;
        int end;
        std::string style;
        std::string link;

        bool operator < (const Style &s)const {
            return start < s.start;
        }
    };
    void from_json(const json& j, Style& s);
}


#endif //STYLE_HPP
