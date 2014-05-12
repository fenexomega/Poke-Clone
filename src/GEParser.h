#ifndef GEPARSER_H
#define GEPARSER_H

#include "GEGlobal.h"
#include <fstream>
#include <vector>
#include "jsoncpp/json/json.h"
#include "Game/Game_Classes/GameObject.h"

//TODO Everything

using namespace std;


class GEParser
{
private:

public:
    static void ReadMapData(string filename,string array,string index,int matrix[][GE_GLOBAL_MAP_WIDTH_IN_TILES]);
    static vector<GameObject *> ReadObjectData(string filename1);
};

#endif // GEPARSER_H
