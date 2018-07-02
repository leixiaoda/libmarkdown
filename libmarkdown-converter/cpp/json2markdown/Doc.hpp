//
// Created by chenlong.01 on 2018/5/23.
//

#ifndef DOC_HPP
#define DOC_HPP

#include <string>
#include "Block.hpp"

namespace Sunrise
{
    struct Doc
    {
        std::string id;
        int folderId;
        std::string author;
        int createTime;
        int lastModify;
        std::string version;
        std::vector<Block> blocks;
    };
    void from_json(const json& j, Doc& d);
}

#endif //DOC_HPP
