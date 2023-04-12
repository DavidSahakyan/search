#include "search.hpp"
#include "search_keywords.hpp"

int main()
{
    search("C:/Users/hp/Desktop/test", "test");
    std::cout<<keyword_exists("C:/Users/hp/Desktop/test/testfile.txt", "test");
    for(std::filesystem::path element : res)
    {
        std::cout<<element<<std::endl;
    }
}