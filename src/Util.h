#ifndef UTIL_H_
#define UTIL_H_

#include <string>

static uint32_t FNVHash(std::string str)
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


#endif /* UTIL_H_ */
