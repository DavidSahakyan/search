
#ifndef EXECUTE_SEARCH_KEYWORDS_HPP
#define EXECUTE_SEARCH_KEYWORDS_HPP

#include <iostream>
#include <queue>
#include <filesystem>
#include <vector>
#include <chrono>
#include "search_keywords.hpp"
#include "external_mutex.hpp"

std::filesystem::path queue_top;

void execute_search_keyword(std::queue<std::filesystem::path>& files_queue,
                            const std::string& keyword, bool& done,
                            std::vector<std::filesystem::path>& res)
{
    while(true)
    {
        if(files_queue.empty() && done == true)
        {
            break;
        }

        if(files_queue.empty())
        {
            std::this_thread::sleep_for (std::chrono::milliseconds(1));
        }

        queue_mutex.lock();
        if(!files_queue.empty())
        {
            queue_top = files_queue.front();
            files_queue.pop();
            queue_mutex.unlock();
            if(search_keywords(queue_top, keyword) == true)
            {
                queue_mutex.lock();
                res.push_back(queue_top);
                queue_mutex.unlock();
            }
        }
        else
        {
            queue_mutex.unlock();
        }
    }
    return;
}
#endif // EXECUTE_SEARCH_KEYWORDS_HPP
