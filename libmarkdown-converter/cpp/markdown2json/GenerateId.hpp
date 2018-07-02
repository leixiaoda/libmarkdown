#ifndef generate_id_hpp
#define generate_id_hpp
#pragma once

#include <string>
#include <random>

namespace Sunrise {
    static std::string random_string( size_t length )
    {
        auto randchar = []() -> char
        {
            const char charset[] =
            "0123456789"
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            const size_t max_index = (sizeof(charset) - 1);
            std::random_device rd;
            return charset[ rd() % max_index ];
        };

        std::string str(length, 0);
        std::generate_n( str.begin(), length, randchar );

//        __android_log_print(ANDROID_LOG_DEBUG, TAG_MD_TO_JSON, "generated id = %s", str.c_str());

        return str;
    }
}
#endif
