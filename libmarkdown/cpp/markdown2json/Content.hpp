
#ifndef content_hpp
#define content_hpp
#pragma once

#include <string>
#include <vector>
#include "BodyModel.hpp"
#include "../json.h"
#include <unordered_map>

using nlohmann::json;

namespace Sunset {
    class Content {
    public:
        std::string id;
        int folderId = 0;
        long createTime = 0;
        long lastModify = 0;
        std::string version;
        std::string author;
        Sunset::BodyModel blocks;
    };
    void to_json(json& j, const Content& c);
    void from_json(const json& j, Content& p);
}

#endif /* content_hpp */