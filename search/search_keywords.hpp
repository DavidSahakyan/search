
#ifndef SEARCH_KEYWORDS_HPP
#define SEARCH_KEYWORDS_HPP

#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <filesystem>
#include <fstream>
#include <algorithm>


bool KI_checkbox = false;
bool regexp_checkbox = false;

bool search_keywords(const std::filesystem::path& pth, const std::string& keyword)
{
    std::fstream file;
    file.open(pth);
    if(!file.is_open())
    {
        return false;
    }
    else
    {
        std::string line;
        if(!KI_checkbox)
        {
            while(getline(file, line))
            {
                if(regexp_checkbox)
                {
                    std::string keyword_copy = keyword;
                    if(std::regex_match(line, std::regex(keyword_copy)))
                    {
                        file.close();
                        return true;
                    }
                }

                else if(line.find(keyword)  != std::string::npos )
                {
                    file.close();
                    return true;
                }
            }
        }
        else
        {
            while(getline(file, line))
            {
                std::string keyword_copy = keyword;
                std::for_each(line.begin(), line.end(), [](char& c){c = tolower(c);});
                std::for_each(keyword_copy.begin(), keyword_copy.end(), [](char& c){c = tolower(c);});
                if(regexp_checkbox)
                {
                    if(std::regex_match(line, std::regex(keyword_copy)))
                    {
                        file.close();
                        return true;
                    }
                }
                else if(line.find(keyword_copy)  != std::string::npos )
                {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
}


#endif // SEARCH_KEYWORDS_HPP
