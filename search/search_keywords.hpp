
#ifndef SEARCH_KEYWORDS_HPP
#define SEARCH_KEYWORDS_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <thread>
#include <algorithm>

bool checkbox = true;

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
        if(!checkbox)
        {
            while(getline(file, line))
            {
                if(line.find(keyword)  != std::string::npos )
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
                if(line.find(keyword_copy)  != std::string::npos )
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
