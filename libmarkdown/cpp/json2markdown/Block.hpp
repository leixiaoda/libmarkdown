//
// Created by chenlong.01 on 2018/5/24.
//

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include "Style.hpp"

namespace Sunset
{
    struct Block
    {
        std::string id;
        int index;
        std::string type;
        std::string text;
        std::string uri;
        std::vector<Style> styles;
    };
    void from_json(const json& j, Block& b);
}

#endif //BLOCK_HPP
