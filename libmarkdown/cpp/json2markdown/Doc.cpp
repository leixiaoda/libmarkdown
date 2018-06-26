//
// Created by chenlong.01 on 2018/5/23.
//

#include "Doc.hpp"

void Sunset::from_json(const json& j, Doc& d)
{
    d.blocks = j.at("blocks").get<std::vector<Block>>();
}