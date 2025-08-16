#include "FileReader.h"    
#include <fstream>
#include <iostream>    
#include <iterator>

FileReader::FileReader(const std::string& filename): filename_(filename) {}

std::string FileReader::getFileContent()
{
    std::ifstream inputFile(filename_);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename_ << "'" << std::endl;
        return "";
    }
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    return fileContent;
}