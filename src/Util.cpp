#include "Util.h"

uint32_t FNVHash(std::string str)
{
	const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	unsigned int i = 0;
	unsigned int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash *= fnv_prime;
		hash ^= (str[i]);
	}

	return hash;
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
