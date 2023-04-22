
#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <regex>
#include "external_mutex.hpp"
#include "globals.hpp"

std::string filter;
bool file_filter_used = false;

void inner_search(const std::filesystem::path& pth,
                  const std::string& keyword)
{
    if(exists(pth))
    {
        if(is_regular_file(pth) && !file_filter_used)
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
        else if(is_directory(pth))
        {
            for(auto const& direct_ent:std::filesystem::directory_iterator{pth})
            {
                inner_search(direct_ent.path(), keyword);
            }
            return;
        }
    }
}

void search(const std::filesystem::path& pth,
            const std::string& keyword)
{
    inner_search(pth, keyword);
    done = true;
    return;
}

#endif // SEARCH_HPP
