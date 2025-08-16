#include "Application.h" 
#include <iostream>     
#include <string>       
#include <vector>       

Application::Application(const std::string& filename, int pVal, int mVal): fr(filename), rks(pVal,mVal) {}

void Application::run()
{
    std::string userPattern;
    std::string fileText;

    fileText = fr.getFileContent();
    if (fileText.empty())
    {
        std::cout << "Exiting due to file read error." << std::endl;
        return;
    }

    std::cout << "Enter the pattern to search for: ";
    std::cin >> userPattern;

    std::vector<int> results = rks.search(fileText, userPattern);

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