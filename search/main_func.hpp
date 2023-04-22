
#ifndef MAIN_FUNC_HPP
#define MAIN_FUNC_HPP

#include "search.hpp"
#include "execute_search_keywords.hpp"

void main_func(const std::filesystem::path& pth, const std::string& keyword)
{
    std::vector<std::thread> threads;
    const int thread_num = std::thread::hardware_concurrency();
    std::thread queue_filler(search, pth, keyword);
    for(int i = 0; i < thread_num; i++)
    {
        threads.push_back(std::thread(execute_search_keyword, keyword));
    }

    queue_filler.join();
    for(int i = 0; i < thread_num; i++)
    {
        threads[i].join();
    }
}

#endif // MAIN_FUNC_HPP
