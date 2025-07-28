#include "RabinKarpSearcher.h" 
#include <iostream>        
#include <algorithm>      

RabinKarpSearcher::RabinKarpSearcher(int pVal, int mVal) : m_hashUtility(pVal, mVal) {};

std::vector<int> RabinKarpSearcher::search(const std::string& text, const std::string& pattern)
{
    std::vector<int> found_indices;

    int n = text.length();
    int m = pattern.length();

    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    std::cout << "Text length (n): " << n << std::endl;
    std::cout << "Pattern length (m): " << m << std::endl;

    if (m == 0 || n == 0 || m > n)
    {
        std::cout << "Cannot find pattern: Invalid lengths." << std::endl;
        return found_indices;
    }

    m_hashUtility.precomputePPowers(std::max(n, m));

    long long pattern_hash = m_hashUtility.calculateHash(pattern, m);
    long long current_text_hash = m_hashUtility.calculateHash(text, m);

    std::cout << "\nInitial Pattern Hash: " << pattern_hash << std::endl;
    std::cout << "Initial Text Window Hash (text[0..." << m - 1 << "]): " << current_text_hash << std::endl;

    for (int i = 0 ; i <= n - m ; ++i)
    {
        if (current_text_hash == pattern_hash)
        {
            std::cout << "Potential match at index: " << i << std::endl;

            bool match_found = true;
            for (int k = 0 ; k < m ; ++k)
            {
                if (text[i + k] != pattern[k])
                {
                    match_found = false;
                    break;
                }
            }

            if (match_found)
            {
                std::cout << "TRUE Match found at index: " << i << std::endl;
                found_indices.push_back(i);
            }
        }

        if (i < n - m)
        {
            long long char_to_remove_val = (long long)(text[i] - 'a' + 1);
            long long highest_power_of_P = m_hashUtility.getPPowers()[m - 1];
            int current_P = m_hashUtility.getP();
            int current_M = m_hashUtility.getM();

            current_text_hash = (current_text_hash - char_to_remove_val * highest_power_of_P) % current_M;

            if (current_text_hash < 0)
            {
                current_text_hash += current_M;
            }
            current_text_hash = (current_text_hash * current_P) % current_M;
            current_text_hash = (current_text_hash + (long long)(text[i + m] - 'a' + 1)) % current_M;
        }
    }
    return found_indices;
}