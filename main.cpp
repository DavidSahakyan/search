#include "search.hpp"
#include "search_keywords.hpp"

int main()
{
    search("C:/Users/hp/Desktop/test", "test");
    for(std::filesystem::path element : res)
    {
        std::cout<<element<<std::endl;
    }
}