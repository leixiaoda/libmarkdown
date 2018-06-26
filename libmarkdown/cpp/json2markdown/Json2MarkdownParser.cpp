//
// Created by chenlong.01 on 2018/5/23.
//

#include "Json2MarkdownParser.hpp"
#include "../wstring_utils.hpp"
#include "Block.hpp"

std::string Sunset::json_to_markdown(std::string json_str)
{
    std::string markdown_str;

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
                markdown_str = markdown_str + "# " + block.text + "\n";
            }
            else if (H2 == block.type)
            {
                markdown_str = markdown_str + "## " + block.text + "\n";
            }
            else if (H3 == block.type)
            {
                markdown_str = markdown_str + "### " + block.text + "\n";
            }
            else if (PARAGRAPH == block.type)
            {
                if (block.styles.size() <= 0)
                {
                    markdown_str = markdown_str + block.text + "\n";
                }
                else
                {
                    std::wstring wstr = Sunset::string2wstring(block.text);

                    // sort the styles
                    std::sort(block.styles.begin(), block.styles.end());
//                    for (int ii = 0 ; ii < block.styles.size(); ii++) {
//                        __android_log_print(ANDROID_LOG_DEBUG, "json2markdown", "style.start = %d, style.end = %d",
//                                            block.styles[ii].start, block.styles[ii].end);
//                    }
                    Style style;
                    // previous style's end index
                    int previous_index = 0;
                    int j = 0;
                    for (; j < block.styles.size(); j++)
                    {
                        style = block.styles.at(j);
                        markdown_str += Sunset::wstring2string(
                                wstr.substr(previous_index, block.styles.at(j).start - previous_index));
                        if (STR_ITALIC == style.style)
                        {
                            markdown_str = markdown_str + "*" + Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start))
                                    + "*";
                        }
                        else if (STR_BOLD == style.style)
                        {
                            markdown_str = markdown_str + "**" + Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start))
                                           + "**";
                        }
                        else if (STR_LINK == style.style)
                        {
                            markdown_str = markdown_str + "[" + Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start))
                                           + "](" + block.styles.at(j).link + ")";
                        }
                        else if (STR_CODE == style.style)
                        {
                            markdown_str = markdown_str + "`" + Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start))
                                           + "`";
                        }
                        else if (STR_UNDERLINE == style.style)
                        {
                            markdown_str += Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start));
                        }
                        else if (STR_STRIKE_THROUGH == style.style)
                        {
                            markdown_str = markdown_str + "~~" + Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start))
                                           + "~~";
                        }
                        else
                        {
                            markdown_str += Sunset::wstring2string(
                                    wstr.substr(block.styles.at(j).start,
                                                block.styles.at(j).end - block.styles.at(j).start));
                        }
                        previous_index = style.end;
                    }

                    // concatenates the substring after the last style block
                    int start = block.styles.at(j - 1).end;
                    int len = wstr.length() - start;
                    markdown_str = markdown_str + Sunset::wstring2string(
                            wstr.substr(start, len))
                                   + "\n";
                }
            }
            else if (UNORDERED_LIST == block.type)
            {
                markdown_str = markdown_str + "* " + block.text + "\n";
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
                markdown_str = markdown_str + std::to_string(ordered_list_index) + ". " + block.text + "\n";
            }
            else if (IMAGE == block.type)
            {
                markdown_str = markdown_str + "![Image](" + block.uri + ")" + "\n";
            }
            else if (QUOTE == block.type)
            {
                markdown_str = markdown_str + "> " + block.text + "\n";
            }
            else
            {
                markdown_str += block.text;
            }
        }
    }

    return markdown_str;
}
