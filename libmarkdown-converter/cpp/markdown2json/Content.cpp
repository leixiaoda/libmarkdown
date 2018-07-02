
#include "Content.hpp"

using Sunset::Content;

void Sunset::to_json(json &j, const Content& c) {
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
