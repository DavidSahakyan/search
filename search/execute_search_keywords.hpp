
#ifndef EXECUTE_SEARCH_KEYWORDS_HPP
#define EXECUTE_SEARCH_KEYWORDS_HPP
#include <iostream>
#include <queue>
#include <filesystem>
#include <vector>
#include <chrono>
#include "search_keywords.hpp"
#include "external_mutex.hpp"

void execute_search_keyword(std::queue<std::filesystem::path>& files_queue,
                            const std::string& keyword, bool& done,
                            std::vector<std::filesystem::path>& res)
{
    std::filesystem::path current_file;
    while(true)
    {
        queue_mutex.lock();
        if(files_queue.empty() && done)
        {
            queue_mutex.unlock();
            break;
        }

        if(files_queue.empty())
        {
            queue_mutex.unlock();
            std::this_thread::sleep_for (std::chrono::milliseconds(1));
        }
        else
        {
            current_file = files_queue.front();
            files_queue.pop();
            queue_mutex.unlock();

            if(search_keywords(current_file, keyword) == true)
            {
                res_mutex.lock();
                res.push_back(current_file);
                res_mutex.unlock();
            }
        }
    }
    return;
}

#endif // EXECUTE_SEARCH_KEYWORDS_HPP
