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


namespace Sunset { // markdown body-model
    class BodyModel {
    public:
        std::string s;
        std::vector<Sunset::Paragraph> paragraphs;
        void add(Sunset::Paragraph p);
    };
    void to_json(json& j, const BodyModel& p);
    void from_json(const json& j, BodyModel& p);
}

#endif /* BodyModel_hpp */
