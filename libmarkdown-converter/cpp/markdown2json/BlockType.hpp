//
// Created by chenlong.01 on 2018/5/10.
//

#ifndef BLOCKTYPE_HPP
#define BLOCKTYPE_HPP

#include <string>

namespace Sunrise {

    enum BlockType {
        doc,
        h1,
        h2,
        h3,
        h4,
        h5,
        h6,
        paragraph,
        code_block,
        unordered_list,
        ordered_list,
        image,
        block_quote
    };

}

#endif //BLOCKTYPE_HPP
