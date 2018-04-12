#ifndef JSONPARSER_H_INCLUDED
#define JSONPARSER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using json = nlohmann::json;

json deserializeFile(std::string path);



#endif // JSONPARSER_H_INCLUDED
