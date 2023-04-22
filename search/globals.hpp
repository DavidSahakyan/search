
#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include <queue>
#include <vector>
#include <filesystem>

std::queue<std::filesystem::path> files_queue;
std::vector<std::filesystem::path> res;
bool done = false;

#endif // GLOBALS_HPP
