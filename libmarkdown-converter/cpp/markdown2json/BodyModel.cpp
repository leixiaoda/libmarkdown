//
//  BodyModel.cpp
//  MarkdownParser
//
//

#include "BodyModel.hpp"

void Sunset::BodyModel::add(Sunset::Paragraph p) {
    paragraphs.push_back(p);
}

void Sunset::to_json(json& j, const BodyModel& p) {
//    j = json{{"paragraphs", p.paragraphs}};
    j = p.paragraphs;
}

void Sunset::from_json(const json& j, BodyModel& p) {
    p.paragraphs = j.at("id").get<std::vector<Sunset::Paragraph>>();
}
