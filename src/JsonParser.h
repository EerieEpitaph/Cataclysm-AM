#ifndef JSONPARSER_H_INCLUDED
#define JSONPARSER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <stdexcept>

#include "Util.h"
#include "../libs/json.hpp"

#define JSON_ROOT "json/root.json"
using json = nlohmann::json;

std::vector<json> importJSONs(std::string root);



#endif // JSONPARSER_H_INCLUDED
