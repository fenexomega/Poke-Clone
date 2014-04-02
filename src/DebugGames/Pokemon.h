#ifndef POKEMON_H
#define POKEMON_H

#include "../Graphics/GObject.h"

enum types {FIRE,NORMAL,WATER,ELECTRIC,ROCK,PSYCH,GHOST,GRASS,POISON,FLYING};
enum POSE {FRONT,BACK};


class Pokemon : public GObject
{
private:
    long experience;
    char level;
    int element;
    char spriteNmbr;
    char position;
    
    int attack;
    int defense;
    int speed;
    int special;
public:
    Pokemon();
    void Draw();
};

#endif // POKEMON_H
