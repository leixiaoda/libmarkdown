//
// Created by chenlong.01 on 2018/5/23.
//

#include "Json2MarkdownParser.hpp"
#include "../wstring_utils.hpp"
#include "Block.hpp"

std::string Sunrise::json_to_markdown(std::string json_str)
{
    std::wstring markdown_str;

    json doc = json::parse(json_str);
    std::vector<Block> blocks = doc.at("blocks").get<std::vector<Block>>();
    if (blocks.size() > 0)
    {
        Block block;
        int ordered_list_index = 0;
        for (int i = 0; i < blocks.size(); i++)
        {
            block = blocks.at(i);
            if (H1 == block.type)
            {
                markdown_str += Sunrise::string2wstring("# " + block.text + "\n");
            }
            else if (H2 == block.type)
            {
                markdown_str += Sunrise::string2wstring("## " + block.text + "\n");
            }
            else if (H3 == block.type)
            {
                markdown_str += Sunrise::string2wstring("### " + block.text + "\n");
            }
            else if (PARAGRAPH == block.type)
            {
                if (block.styles.size() <= 0)
                {
                    markdown_str += Sunrise::string2wstring(block.text + "\n");
                }
                else
                {
                    std::wstring wstr = Sunrise::string2wstring(block.text);

                    std::vector<InsertPoint> insert_points;
                    for (int ii = 0; ii < block.styles.size(); ++ii)
                    {
                        InsertPoint point;
                        point.index = block.styles[ii].start;
                        point.isStart = true;
                        point.type = block.styles[ii].style;
                        insert_points.push_back(point);

                        InsertPoint point_end;
                        point_end.index = block.styles[ii].end;
                        point_end.isStart = false;
                        point_end.type = block.styles[ii].style;
                        point_end.link = block.styles[ii].link;
                        insert_points.push_back(point_end);
                    }
                    std::sort(insert_points.begin(), insert_points.end());

                    for (int j = insert_points.size() - 1; j >= 0; --j)
                    {
                        InsertPoint point = insert_points.at(j);
                        if (STR_ITALIC == point.type)
                        {
                            wstr.insert(point.index, L"*");
                        }
                        else if (STR_BOLD == point.type)
                        {
                            wstr.insert(point.index, L"**");
                        }
                        else if (STR_LINK == point.type)
                        {
                            if (point.isStart)
                            {
                                wstr.insert(point.index, L"[");
                            }
                            else
                            {
                                std::wstring tmp = L"](" + Sunrise::string2wstring(point.link) + L")";
                                wstr.insert(point.index, tmp);
                            }
                        }
                        else if (STR_CODE == point.type)
                        {
                            wstr.insert(point.index, L"`");
                        }
                        else if (STR_STRIKE_THROUGH == point.type)
                        {
                            wstr.insert(point.index, L"~~");
                        }
                    }

                    markdown_str += wstr;
                }
            }
            else if (UNORDERED_LIST == block.type)
            {
                markdown_str += Sunrise::string2wstring("* " + block.text + "\n");
            }
            else if (ORDERED_LIST == block.type)
            {
                if (i == 0 || blocks.at(i-1).type != ORDERED_LIST)
                {
                    ordered_list_index = 1;
                }
                else
                {
                    ++ordered_list_index;
                }
                markdown_str += Sunrise::string2wstring(std::to_string(ordered_list_index) + ". " + block.text + "\n");
            }
            else if (IMAGE == block.type)
            {
                markdown_str += Sunrise::string2wstring("![Image](" + block.uri + ")" + "\n");
            }
            else if (QUOTE == block.type)
            {
                markdown_str += Sunrise::string2wstring("> " + block.text + "\n");
            }
            else
            {
                markdown_str += Sunrise::string2wstring(block.text);
            }
        }
    }

    std::string ret = Sunrise::wstring2string(markdown_str);

    return ret;
}

