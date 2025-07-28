#ifndef RABIN_KARP_SEARCHER_H
#define RABIN_KARP_SEARCHER_H

#include <string>   
#include <vector>  
#include "HashUtility.h"

class RabinKarpSearcher
{
public:
    RabinKarpSearcher(int pVal, int mVal);

    std::vector<int> search(const std::string& text, const std::string& pattern);

private:
    HashUtility m_hashUtility;
};

#endif