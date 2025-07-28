#include "Application.h" 
#include <iostream>     
#include <string>       
#include <vector>       


void Application::run(int pVal, int mVal)
{
    std::string filename;
    std::string userPattern;
    std::string fileText;

    std::cout << "Enter the filename to search in: ";
    std::cin >> filename;

    fileText = FileReader::readTextFromFile(filename);
    if (fileText.empty())
    {
        std::cout << "Exiting due to file read error." << std::endl;
        return;
    }

    std::cout << "Enter the pattern to search for: ";
    std::cin >> userPattern;

    RabinKarpSearcher searcher(pVal, mVal);

    std::vector<int> results = searcher.search(fileText, userPattern);

    std::cout << "\n Final Results " << std::endl;
    if (results.empty())
    { 
        std::cout << "Pattern '" << userPattern << "' not found in the file." << std::endl;
    }
    else
    {
        std::cout << "Pattern '" << userPattern << "' found at indices: ";
        for (int index : results)
        {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
}