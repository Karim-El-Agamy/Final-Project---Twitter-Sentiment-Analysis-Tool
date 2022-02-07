#include "Dictionary.h"

Dictionary::Dictionary()
{

}

std::map<std::string, int> Dictionary::getDictionary(std::string fileLocation)
{

    const char *cstr = fileLocation.c_str();

    string line;
    ifstream myfile (cstr);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            string arr[2];
            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < 2)
            {
                ssin >> arr[i];
                ++i;
            }
            int value = atoi(arr[1].c_str());
            map[arr[0]] = value;
        }
        myfile.close();
    }

    else
        cout << "Unable to open file \n";

    return map;
}

