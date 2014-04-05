#ifndef POKEMON_H
#define POKEMON_H

#include "../../Graphics/GObject.h"

enum types {FIRE,NORMAL,WATER,ELECTRIC,ROCK,PSYCH,GHOST,GRASS,POISON,FLYING};
enum POSE {FRONT,BACK};
enum STATUS {FINE,FNT,BRN,FRZ,PRZ,PSN,SLP,LEECH,CONFUSION};

class Pokemon : public GObject
{
private:
    long experience;
    short int level;
    int element;
    int spriteNmbr;
    int status;
    int avatar;
    //attacks[4]
    
    unsigned short int attack;
    unsigned short int spcAtk;
    unsigned short int defense;
    unsigned short int spcDef;
    unsigned short int speed;
public:
    int getDamage();
    Pokemon();
    void Draw();
};

#endif // POKEMON_H
