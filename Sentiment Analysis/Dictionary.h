#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Dictionary.h"


using namespace std;

class Dictionary
{
private:
    std::map<std::string, int> map;

public:
    Dictionary();
    std::map<std::string, int> getDictionary(std::string fileLocation);
};

#endif
