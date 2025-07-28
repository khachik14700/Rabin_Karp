#include "FileReader.h"    
#include <fstream>
#include <iostream>    
#include <iterator>

std::string FileReader::readTextFromFile(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return "";
    }
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    return fileContent;
}