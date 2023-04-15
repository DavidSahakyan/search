
#ifndef MAIN_FUNC_HPP
#define MAIN_FUNC_HPP

#include "search.hpp"
#include "execute_search_keywords.hpp"

std::vector<std::filesystem::path> main_func(const std::filesystem::path& pth, const std::string& keyword)
{
    std::queue<std::filesystem::path> files_queue = {};
    std::vector<std::filesystem::path> res = {};
    std::thread queue_filler(search_with_flag, pth, keyword, std::ref(files_queue));
    std::thread w1(execute_search_keyword, std::ref(files_queue), keyword, std::ref(done), std::ref(res));
    std::thread w2(execute_search_keyword, std::ref(files_queue), keyword, std::ref(done), std::ref(res));
    std::thread w3(execute_search_keyword, std::ref(files_queue), keyword, std::ref(done), std::ref(res));

    queue_filler.join();
    w1.join();
    w2.join();
    w3.join();

    return res;
}

#endif // MAIN_FUNC_HPP
