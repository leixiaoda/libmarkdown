//
// Created by chenlong.01 on 2018/5/24.
//

#include "Style.hpp"

void Sunset::from_json(const json& j, Style& s)
{
    s.start = j.at("start").get<int>();
    s.end = j.at("end").get<int>();
    s.style = j.at("style").get<std::string>();
    if (j.find("link") != j.end())
    {
        s.link = j.at("link").get<std::string>();
    }
}