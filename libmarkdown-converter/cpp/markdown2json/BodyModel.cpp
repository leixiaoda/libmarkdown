//
//  BodyModel.cpp
//  MarkdownParser
//
//

#include "BodyModel.hpp"

void Sunrise::BodyModel::add(Sunrise::Paragraph p) {
    paragraphs.push_back(p);
}

void Sunrise::to_json(json& j, const BodyModel& p) {
//    j = json{{"paragraphs", p.paragraphs}};
    j = p.paragraphs;
}

void Sunrise::from_json(const json& j, BodyModel& p) {
    p.paragraphs = j.at("id").get<std::vector<Sunrise::Paragraph>>();
}
