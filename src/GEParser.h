#ifndef GEPARSER_H
#define GEPARSER_H

#include "GEGlobal.h"
#include <fstream>
#include <vector>
#include <jsoncpp/json/json.h>
//TODO Everything

using namespace std;


class GEParser
{
private:

public:
    GEParser(string filename);
    static void ReadMapData(string filename,string array,string index,int matrix[][GE_GLOBAL_MAP_WIDTH_IN_TILES]);
};

#endif // GEPARSER_H
