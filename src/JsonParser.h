#ifndef JSONPARSER_H_INCLUDED
#define JSONPARSER_H_INCLUDED

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <stdexcept>

#include "Item.h"
#include "Database.h"
#include "Util.h"
#include "Exceptions.h"
#include "../libs/json.hpp"

#define JSON_ROOT "json/root.json"
using json = nlohmann::json;

std::vector<json> importJSONs(std::string root);
Database processJsons(std::vector<json> in);
std::vector<uint32_t> importFlags(json j);
void importItem(std::unordered_map<uint32_t, Item&> items, json j);

#endif // JSONPARSER_H_INCLUDED
