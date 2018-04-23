#ifndef JSONPARSER_H_INCLUDED
#define JSONPARSER_H_INCLUDED

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <stdexcept>

#include "Item.h"
#include "Magazine.h"
#include "Database.h"
#include "Util.h"
#include "Exceptions.h"
#include "../libs/json.hpp"

#define JSON_ROOT "json/root.json"
using json = nlohmann::json;

static uint32_t flagIndex = 0;

std::vector<json> importJSONs(std::string root);
Database processJsons(std::vector<json> in);
std::unordered_map<std::string, uint32_t> importFlags(json j);
void importItem(std::unordered_map<std::string, Item&>& items, json j);
Magazine& castMagazine(json j);

#endif // JSONPARSER_H_INCLUDED
