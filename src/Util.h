#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>
#include <algorithm>

uint32_t FNVHash(std::string str);
bool flagInVect(std::vector<uint32_t> vect, uint32_t item);

std::string extractPath(std::string path);
std::string extractDir(std::string path);


#endif /* UTIL_H_ */
