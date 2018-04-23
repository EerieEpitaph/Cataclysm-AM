#include "JsonParser.h"

std::vector<json> importJSONs(std::string root)
{
    std::string contextDir = extractDir(root);
    std::string buf;
    std::string line;
    std::stack<char> curlyCount;
    std::vector<json> jOut;
    std::ifstream fileHandler(root);

    if(!fileHandler.is_open())
        throw std::logic_error("Bad file opening");

    while(getline(fileHandler, line))
    {
        auto firstChar = line.find_first_not_of(' ');
        if(firstChar == std::string::npos)
            continue;

        if( (firstChar >= 0 && firstChar <= line.length()) )
        {
            if( line[firstChar] == '@') //Recursive includer
            {
                std::string linePath = extractPath(line.substr(firstChar+1, line.length()));
                std::vector<json> inner = importJSONs(contextDir + linePath);
                for( json j : inner )
                    jOut.push_back(j);
                continue;
            }

            if( line[firstChar] == '{' ) //Curly-bracket stack
                curlyCount.push(line[firstChar]);
            else if( line[firstChar] == '}' )
                curlyCount.pop();

            if(line[firstChar] != '#') //Comment
            {
                buf += line;
                if(curlyCount.size() == 0 )
                {
                    jOut.push_back(json::parse(buf));
                    buf.clear();
                }
            }
        }
        else
            throw line_analysis_exception();
    }

    fileHandler.close();
    return jOut;
}

Database processJsons(std::vector<json> in)
{
    Database gameData;
    std::unordered_map<std::string, uint32_t> flags;
    std::unordered_map<std::string, Item&> items;

    for(json j : in)
    {
        if(j["I_AM"] == "flags")
            flags = importFlags(j);
        else if(j["I_AM"] == "item")
            importItem(items, j);
    }

    return gameData;
}

std::unordered_map<std::string, uint32_t> importFlags(json j)
{
    std::unordered_map<std::string, uint32_t> foundFlags;

    for(std::string flagLiteral : j["FLAGS"])
    {
        flagIndex++;
        if(Database::getFlags().count(flagLiteral) == 0) //Avoid redefinition of flags
            Database::addInto(foundFlags, flagLiteral, flagIndex);
        else
            throw redefinition_exception();
    }
    return foundFlags;
}

void importItem(std::unordered_map<std::string, Item&>& items, json j)
{
    if(j["I_AM"] != "item"){}
        throw identifier_mismatch_exception();

    //switch based on "I_AM"
}

Magazine& castMagazine(json j)
{

}
