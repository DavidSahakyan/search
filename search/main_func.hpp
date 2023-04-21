
#ifndef MAIN_FUNC_HPP
#define MAIN_FUNC_HPP

#include "search.hpp"
#include "execute_search_keywords.hpp"

std::vector<std::filesystem::path> main_func(const std::filesystem::path& pth, const std::string& keyword)
{
    std::queue<std::filesystem::path> files_queue = {};
    std::vector<std::filesystem::path> res = {};
    std::vector<std::thread> threads;
    const int thread_num = std::thread::hardware_concurrency();
    std::thread queue_filler(search_with_flag, pth, keyword, std::ref(files_queue));
    for(int i = 0; i < thread_num; i++)
    {
        threads.push_back(std::thread(execute_search_keyword, std::ref(files_queue), keyword, std::ref(done), std::ref(res)));
    }    
    queue_filler.join();
    for(int i = 0; i < thread_num; i++)
    {
        threads[i].join();
    }

    done = false;
    return res;
}

#endif // MAIN_FUNC_HPP
