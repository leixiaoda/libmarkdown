
#include "Content.hpp"

using Sunrise::Content;

void Sunrise::to_json(json &j, const Content& c) {
    j = json{
        {"id", c.id},
        {"folderId", c.folderId},
        {"createTime", c.createTime},
        {"lastModify", c.lastModify},
        {"version", c.version},
        {"author", c.author},
        {"blocks", c.blocks}
    };
}
