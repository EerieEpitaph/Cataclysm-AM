#include "Database.h"

std::unordered_map<std::string, uint32_t> Database::flags = std::unordered_map<std::string, uint32_t>();
std::unordered_map<std::string, Item&> Database::items = std::unordered_map<std::string, Item&>();
