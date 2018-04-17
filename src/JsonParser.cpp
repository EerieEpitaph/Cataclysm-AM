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
            if( line[firstChar] == '@')
            {
                std::string linePath = extractPath(line.substr(firstChar+1, line.length()));
                std::vector<json> inner = importJSONs(contextDir + linePath);
                for( json j : inner )
                    jOut.push_back(j);
                continue;
            }

            if( line[firstChar] == '{' )
                curlyCount.push(line[firstChar]);
            else if( line[firstChar] == '}' )
                curlyCount.pop();

            if(line[firstChar] != '#')
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
            throw std::out_of_range("Line analysis failed");
    }

    fileHandler.close();
    return jOut;
}

Database processJsons(std::vector<json> in)
{
    std::vector<uint32_t> flags;

    for(json j : in)
    {
        if(j["I_AM"] == "flags")
            flags = importFlags(j);
    }
}

std::vector<uint32_t> importFlags(json j)
{
    std::vector<uint32_t> foundFlags;

    //if(j["I_AM"] != "flags")
    //   throw std::logic_error("Not a flag definition JSON");
    //for(auto x : j["flags"])
        //std::cout << x;

    return foundFlags;
}
