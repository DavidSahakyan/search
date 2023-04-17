#include <cstdlib>
#include <filesystem>

#ifdef _WIN32

void openf(std::filesystem::path p)
{
    std::system(("start " + p.string()).c_str());
    return;
}

#elif defined __APPLE__

void openf(std::filesystem::path p)
{
    std::system(("open " + p.string()).c_str());
    return;
}

#elif defined __linux__

void openf(std::filesystem::path p)
{
    std::system(("xdg-open " + p.string()).c_str());
    return;
}

#endif
