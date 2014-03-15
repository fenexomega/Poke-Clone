/*
 * Input.h
 *
 *  Created on: 13/02/2014
 *      Author: jordy
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "SDL/SDL.h"
using namespace std;

#define NUM_KEYCODES 512

extern Uint8 * keys;
extern vector<int> downKeys;
extern vector<int> upKeys;
extern vector<int> currentKeys;

class GEInput
{
private:

public:
	static void update()
	{
		keys = SDL_GetKeyState(NULL);
		int i;
		//TODO Mouse Unput!
				upKeys.clear();
				for(i = 0; i < NUM_KEYCODES; i++)
					if(!getKey(i) && (find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()) )
						upKeys.push_back(i);

				downKeys.clear();
				for(i = 0; i < NUM_KEYCODES; i++)
					if(getKey(i) && !(find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()))
						downKeys.push_back(i);

				currentKeys.clear();
				for(i = 0; i < NUM_KEYCODES; i++)
					if(getKey(i))
						currentKeys.push_back(i);
	}

	static bool isKeyUp(int x)
	{
		return find(upKeys.begin(),upKeys.end(),x) != upKeys.end();
	}

	static bool isKeyDown(int x)
	{
		return find(downKeys.begin(),downKeys.end(),x) != downKeys.end();
	}

	static bool isKeyPressed(int x)
	{
		return find(currentKeys.begin(),currentKeys.end(),x) != currentKeys.end();
	}

    static bool isAnyKeyDown()
    {
        for(int i = 0; i < 300; i++)
            if(isKeyPressed(i) || isKeyDown(i))
                return true;
        return false;
    }

	static bool getKey(int key)
	{
		return keys[key] == 1;
	}
};

#endif /* INPUT_H_ */
