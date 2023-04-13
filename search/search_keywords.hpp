
#ifndef SEARCH_KEYWORDS_HPP
#define SEARCH_KEYWORDS_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

bool keyword_exists(const std::filesystem::path& pth,const std::string& keyword)
{
    std::ifstream file;
    file.open(pth);
    if(!file.is_open())
    {
        return false;
    }
    else
    {
        std::string line;
        while(getline(file, line))
        {
            if(line.find(keyword)  != std::string::npos )
            {
                return true;
            }
        }
        return false;
    }
}
#endif // SEARCH_KEYWORDS_HPP
