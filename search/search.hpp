
#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "search_keywords.hpp"

std::vector<std::string> res{};
void search(const std::filesystem::path& pth, const std::string& keyword)
{
    if(exists(pth))
    {
        if(is_regular_file(pth) == true)
        {
            if(keyword_exists(pth, keyword))
            {
                res.push_back(pth.u8string());
            }
        }
        else if(is_directory(pth) == true)
        {
            for(auto const& direct_ent:std::filesystem::directory_iterator{pth})
            {
                search(direct_ent.path(), keyword);
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        res.push_back("cant find the path");
    }
}
#endif // SEARCH_HPP
