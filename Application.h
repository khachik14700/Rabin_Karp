#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

#include "FileReader.h"
#include "RabinKarpSearcher.h"

class Application
{
private:
    FileReader fr;
    RabinKarpSearcher rks;

public:
    Application(const std::string& filename, int pVal, int mVal);

    void run();
};

#endif