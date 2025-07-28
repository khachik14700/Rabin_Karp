#include "HashUtility.h"

HashUtility::HashUtility( int pVal , int mVal)
{
    m_P = pVal;
    m_M = mVal;
}

void HashUtility::precomputePPowers(int max_len)
{
    m_pPowers.resize(max_len + 1);
    m_pPowers[0] = 1;
    for (int i = 1 ; i <= max_len ; ++i)
    {
        m_pPowers[i] = (m_pPowers[i - 1] * m_P) % m_M;
    }
} 

long long HashUtility::calculateHash(const std::string& s, int len)
{
    long long hash = 0;
    for (int i = 0 ; i < len ; ++i)
    {
        long long contribution = (long long)(s[i] - 'a' + 1) * m_pPowers[len - 1 - i];
        hash = (hash + contribution) % m_M;
    }
    return hash;
}

int HashUtility::getP() const { return m_P; }
int HashUtility::getM() const { return m_M; }
const std::vector<long long>& HashUtility::getPPowers() const { return m_pPowers; }