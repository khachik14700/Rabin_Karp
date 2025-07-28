#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader
{
public:
    static std::string readTextFromFile(const std::string& filename);
};

#endif