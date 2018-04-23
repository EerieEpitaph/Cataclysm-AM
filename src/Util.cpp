#include "Util.h"

bool flagInVect(std::vector<uint32_t> vect, uint32_t item)
{
    if(std::find(vect.begin(), vect.end(), item) != vect.end())
        return true;
    else
        return false;
}

std::string extractPath(std::string path)
{
    for(uint32_t i = 0; i < path.length(); i++)
    {
        if( !(path[i] == ' ') )
            return path.substr(i, path.length());
    }
    return path;
}

std::string extractDir(std::string path)
{
    return path.substr(0, path.find_last_of("\\/")+1);
}
