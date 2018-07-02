//
//  BodyModel.hpp
//  MarkdownParser
//
//

#ifndef BodyModel_hpp
#define BodyModel_hpp

#include <stdio.h>
#include <vector>
#include "../json.h"
#include "Paragraph.hpp"

using nlohmann::json;


namespace Sunrise { // markdown body-model
    class BodyModel {
    public:
        std::string s;
        std::vector<Sunrise::Paragraph> paragraphs;
        void add(Sunrise::Paragraph p);
    };
    void to_json(json& j, const BodyModel& p);
    void from_json(const json& j, BodyModel& p);
}

#endif /* BodyModel_hpp */
