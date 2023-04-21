
#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <filesystem>
#include <regex>
#include "external_mutex.hpp"

std::string filter;
bool file_filter_used = false;

bool done = false;
void search(const std::filesystem::path& pth, const std::string& keyword,
            std::queue<std::filesystem::path>& files_queue)
{
    if(exists(pth))
    {
        if(is_regular_file(pth) == true && !file_filter_used)
        {
            queue_mutex.lock();
            files_queue.push(pth);
            queue_mutex.unlock();
            return;
        }
        if(is_regular_file(pth) && file_filter_used)
        {
            if(std::regex_match(pth.string(), std::regex(filter)))
            {
                queue_mutex.lock();
                files_queue.push(pth);
                queue_mutex.unlock();
            }
        }
        else if(is_directory(pth) == true)
        {
            for(auto const& direct_ent:std::filesystem::directory_iterator{pth})
            {
                search(direct_ent.path(), keyword, files_queue);
            }
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}

void search_with_flag(const std::filesystem::path& pth, const std::string& keyword,
                      std::queue<std::filesystem::path>& files_queue)
{
    search(pth, keyword, files_queue);
    done = true;
    return;
}

#endif // SEARCH_HPP
