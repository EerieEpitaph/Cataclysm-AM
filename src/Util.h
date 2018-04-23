#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>
#include <algorithm>

bool flagInVect(std::vector<uint32_t> vect, uint32_t item);

std::string extractPath(std::string path);
std::string extractDir(std::string path);


#endif /* UTIL_H_ */
