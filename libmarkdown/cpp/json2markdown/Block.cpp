//
// Created by chenlong.01 on 2018/5/24.
//

#include "Block.hpp"

void Sunset::from_json(const json& j, Block& b)
{
    b.id = j.at("id").get<std::string>();
    b.index = j.at("index").get<int>();
    b.type = j.at("type").get<std::string>();
    if (j.find("text") != j.end())
    {
        b.text = j.at("text").get<std::string>();
    }
    if (j.find("uri") != j.end())
    {
        b.uri = j.at("uri").get<std::string>();
    }
    if (j.find("styles") != j.end())
    {
        b.styles = j.at("styles").get<std::vector<Style>>();
    }
}