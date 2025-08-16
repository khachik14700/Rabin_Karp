#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader
{
private:
    std::string filename_;

public:
    FileReader(const std::string& filename);

    std::string getFileContent();
};

#endif