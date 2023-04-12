#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "search_keywords.hpp"

std::vector<std::filesystem::path> res{};
void search(std::filesystem::path pth, std::string keyword)
    {
        if(exists(pth))
        {
            if(is_regular_file(pth) == true)
            {
                if(keyword_exists(pth, keyword))
                {
                    res.push_back(pth);
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
            std::cout<<"path is invalid";
        }
    }