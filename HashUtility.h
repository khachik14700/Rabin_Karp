#ifndef HASH_UTILITY_H
#define HASH_UTILITY_H

#include <string>
#include <vector>

class HashUtility
{
public:
    HashUtility(int pVal , int mVal);

    void precomputePPowers(int max_len);
    long long calculateHash(const std::string& s, int len);

    int getP() const;
    int getM() const;
    const std::vector<long long>& getPPowers() const;

private:
    int m_P;
    int m_M;
    std::vector<long long> m_pPowers;
};


#endif