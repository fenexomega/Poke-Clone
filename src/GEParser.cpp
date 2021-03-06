#include "GEParser.h"



void GEParser::ReadMapData(string filename1,string objectName,string index,int matrix[][GE_GLOBAL_MAP_WIDTH_IN_TILES])
{
    
    Json::Reader reader;
    Json::Value root;
    Json::Value array;
    filename1 = GE_GLOBAL_FILE_PATH + filename1;
    ifstream file;
    int z;
    
    file.open(filename1.c_str());
    //Pegue todo o conteúdo do arquivo
    
    
    if(reader.parse(file,root,false) == false)
        GE_LOG(reader.getFormatedErrorMessages());
    
    
    array = root["layers"];
    
    for(z = 0; z < array.size(); ++z)
        if(array[z]["name"] == objectName)
            break;
    
    
    for(int y = 0, i = 0; y < GE_GLOBAL_MAP_HEIGHT_IN_TILES; ++y)
    {
        for(int x = 0; x < GE_GLOBAL_MAP_WIDTH_IN_TILES; ++x)
            matrix[x][y] = array[z]["data"][i++].asInt();
    }
    
    
}

vector<GameObject *> GEParser::ReadObjectData(string filename1)
{
    vector<GameObject *> vect;
    GameObject * auxObj;
    Json::Reader reader;
    Json::Value root;
    Json::Value array;
    filename1 = GE_GLOBAL_FILE_PATH + filename1;
    ifstream file;
    int z;
    
    file.open(filename1.c_str());
    
    if(reader.parse(file,root,false) == false)
        GE_LOG(reader.getFormatedErrorMessages());
    
    
    array = root["layers"];
    
    for(z = 0; z < array.size(); ++z)
        if(array[z]["name"] == "Conversaveis")
            break;
    
    
    
    for(unsigned int i = 0; i < array[z]["objects"].size(); ++i)
    {
        auxObj = new GameObject(array[z]["objects"][i]["x"].asInt()/16,
                array[z]["objects"][i]["y"].asInt()/16,
                0,
                array[z]["objects"][i]["properties"]["string"].asString());
        vect.push_back(auxObj);
    }
    
    
    return vect;
}
