#include "JsonParser.h"

json deserializeFile(std::string path)
{
    json j;
    std::ifstream fileHandler(path);

    if(fileHandler.is_open())
        return json::parse(fileHandler);

    throw std::exception();
}
