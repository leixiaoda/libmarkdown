//
// Created by chenlong.01 on 2018/5/23.
//

#ifndef WSTRING_UTILS_HPP
#define WSTRING_UTILS_HPP

#include <string>
#include <codecvt>
#include <locale>

namespace Sunrise
{
    std::wstring string2wstring(const std::string& str);
    std::string wstring2string(const std::wstring& wstr);
};

#endif //WSTRING_UTILS_HPP
