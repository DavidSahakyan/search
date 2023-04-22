
#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include <queue>
#include <vector>
#include <filesystem>

std::queue<std::filesystem::path> queue;
std::queue<std::filesystem::path>& files_queue = queue;
std::vector<std::filesystem::path> vector;
std::vector<std::filesystem::path>& res = vector;
bool d = false;
bool& done = d;

#endif // GLOBALS_HPP
