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
    static const short int UNKNOWN		= 0;
    static const short int FIRST		= 0;
    static const short int BACKSPACE		= 8;
    static const short int TAB		= 9;
    static const short int CLEAR		= 12;
    static const short int RETURN		= 13;
    static const short int PAUSE		= 19;
    static const short int ESCAPE		= 27;
    static const short int SPACE		= 32;
    static const short int EXCLAIM		= 33;
    static const short int QUOTEDBL		= 34;
    static const short int HASH		= 35;
    static const short int DOLLAR		= 36;
    static const short int AMPERSAND		= 38;
    static const short int QUOTE		= 39;
    static const short int LEFTPAREN		= 40;
    static const short int RIGHTPAREN		= 41;
    static const short int ASTERISK		= 42;
    static const short int PLUS		= 43;
    static const short int COMMA		= 44;
    static const short int MINUS		= 45;
    static const short int PERIOD		= 46;
    static const short int SLASH		= 47;
    static const short int Number_0			= 48;
    static const short int Number_1			= 49;
    static const short int Number_2			= 50;
    static const short int Number_3			= 51;
    static const short int Number_4			= 52;
    static const short int Number_5			= 53;
    static const short int Number_6			= 54;
    static const short int Number_7			= 55;
    static const short int Number_8			= 56;
    static const short int Number_9			= 57;
    static const short int COLON		= 58;
    static const short int SEMICOLON		= 59;
    static const short int LESS		= 60;
    static const short int EQUALS		= 61;
    static const short int GREATER		= 62;
    static const short int QUESTION		= 63;
    static const short int AT			= 64;
    /*
       Skip uppercase letters
     */
    static const short int LEFTBRACKET	= 91;
    static const short int BACKSLASH		= 92;
    static const short int RIGHTBRACKET	= 93;
    static const short int CARET		= 94;
    static const short int UNDERSCORE		= 95;
    static const short int BACKQUOTE		= 96;
    static const short int a			= 97;
    static const short int b			= 98;
    static const short int c			= 99;
    static const short int d			= 100;
    static const short int e			= 101;
    static const short int f			= 102;
    static const short int g			= 103;
    static const short int h			= 104;
    static const short int i			= 105;
    static const short int j			= 106;
    static const short int k			= 107;
    static const short int l			= 108;
    static const short int m			= 109;
    static const short int n			= 110;
    static const short int o			= 111;
    static const short int p			= 112;
    static const short int q			= 113;
    static const short int r			= 114;
    static const short int s			= 115;
    static const short int t			= 116;
    static const short int u			= 117;
    static const short int v			= 118;
    static const short int w			= 119;
    static const short int x			= 120;
    static const short int y			= 121;
    static const short int z			= 122;
    static const short int Delete		= 127;
    /* End of ASCII mapped keysyms */
        /*@}*/

    /** @name International keyboard syms */
        /*@{*/
    static const short int WORLD0		= 160;		/* 0xA0 */
    static const short int WORLD1		= 161;
    static const short int WORLD2		= 162;
    static const short int WORLD3		= 163;
    static const short int WORLD4		= 164;
    static const short int WORLD5		= 165;
    static const short int WORLD6		= 166;
    static const short int WORLD7		= 167;
    static const short int WORLD8		= 168;
    static const short int WORLD9		= 169;
    static const short int WORLD10		= 170;
    static const short int WORLD11		= 171;
    static const short int WORLD12		= 172;
    static const short int WORLD13		= 173;
    static const short int WORLD14		= 174;
    static const short int WORLD15		= 175;
    static const short int WORLD16		= 176;
    static const short int WORLD17		= 177;
    static const short int WORLD18		= 178;
    static const short int WORLD19		= 179;
    static const short int WORLD20		= 180;
    static const short int WORLD21		= 181;
    static const short int WORLD22		= 182;
    static const short int WORLD23		= 183;
    static const short int WORLD24		= 184;
    static const short int WORLD25		= 185;
    static const short int WORLD26		= 186;
    static const short int WORLD27		= 187;
    static const short int WORLD28		= 188;
    static const short int WORLD29		= 189;
    static const short int WORLD30		= 190;
    static const short int WORLD31		= 191;
    static const short int WORLD32		= 192;
    static const short int WORLD33		= 193;
    static const short int WORLD34		= 194;
    static const short int WORLD35		= 195;
    static const short int WORLD36		= 196;
    static const short int WORLD37		= 197;
    static const short int WORLD38		= 198;
    static const short int WORLD39		= 199;
    static const short int WORLD40		= 200;
    static const short int WORLD41		= 201;
    static const short int WORLD42		= 202;
    static const short int WORLD43		= 203;
    static const short int WORLD44		= 204;
    static const short int WORLD45		= 205;
    static const short int WORLD46		= 206;
    static const short int WORLD47		= 207;
    static const short int WORLD48		= 208;
    static const short int WORLD49		= 209;
    static const short int WORLD50		= 210;
    static const short int WORLD51		= 211;
    static const short int WORLD52		= 212;
    static const short int WORLD53		= 213;
    static const short int WORLD54		= 214;
    static const short int WORLD55		= 215;
    static const short int WORLD56		= 216;
    static const short int WORLD57		= 217;
    static const short int WORLD58		= 218;
    static const short int WORLD59		= 219;
    static const short int WORLD60		= 220;
    static const short int WORLD61		= 221;
    static const short int WORLD62		= 222;
    static const short int WORLD63		= 223;
    static const short int WORLD64		= 224;
    static const short int WORLD65		= 225;
    static const short int WORLD66		= 226;
    static const short int WORLD67		= 227;
    static const short int WORLD68		= 228;
    static const short int WORLD69		= 229;
    static const short int WORLD70		= 230;
    static const short int WORLD71		= 231;
    static const short int WORLD72		= 232;
    static const short int WORLD73		= 233;
    static const short int WORLD74		= 234;
    static const short int WORLD75		= 235;
    static const short int WORLD76		= 236;
    static const short int WORLD77		= 237;
    static const short int WORLD78		= 238;
    static const short int WORLD79		= 239;
    static const short int WORLD80		= 240;
    static const short int WORLD81		= 241;
    static const short int WORLD82		= 242;
    static const short int WORLD83		= 243;
    static const short int WORLD84		= 244;
    static const short int WORLD85		= 245;
    static const short int WORLD86		= 246;
    static const short int WORLD87		= 247;
    static const short int WORLD88		= 248;
    static const short int WORLD89		= 249;
    static const short int WORLD90		= 250;
    static const short int WORLD91		= 251;
    static const short int WORLD92		= 252;
    static const short int WORLD93		= 253;
    static const short int WORLD94		= 254;
    static const short int WORLD95		= 255;		/* 0xFF */
        /*@}*/

    /** @name Numeric keypad */
        /*@{*/
    static const short int KP0		= 256;
    static const short int KP1		= 257;
    static const short int KP2		= 258;
    static const short int KP3		= 259;
    static const short int KP4		= 260;
    static const short int KP5		= 261;
    static const short int KP6		= 262;
    static const short int KP7		= 263;
    static const short int KP8		= 264;
    static const short int KP9		= 265;
    static const short int KPPERIOD		= 266;
    static const short int KPDIVIDE		= 267;
    static const short int KPMULTIPLY	= 268;
    static const short int KPMINUS		= 269;
    static const short int KPPLUS		= 270;
    static const short int KPENTER		= 271;
    static const short int KPEQUALS		= 272;
        /*@}*/

    /** @name Arrows + Home/End pad */
        /*@{*/
    static const short int UP			= 273;
    static const short int DOWN		= 274;
    static const short int RIGHT		= 275;
    static const short int LEFT		= 276;
    static const short int INSERT		= 277;
    static const short int HOME		= 278;
    static const short int END		= 279;
    static const short int PAGEUP		= 280;
    static const short int PAGEDOWN		= 281;
        /*@}*/

    /** @name Function keys */
        /*@{*/
    static const short int F1			= 282;
    static const short int F2			= 283;
    static const short int F3			= 284;
    static const short int F4			= 285;
    static const short int F5			= 286;
    static const short int F6			= 287;
    static const short int F7			= 288;
    static const short int F8			= 289;
    static const short int F9			= 290;
    static const short int F10		= 291;
    static const short int F11		= 292;
    static const short int F12		= 293;
    static const short int F13		= 294;
    static const short int F14		= 295;
    static const short int F15		= 296;
        /*@}*/

    /** @name Key state modifier keys */
        /*@{*/
    static const short int NUMLOCK		= 300;
    static const short int CAPSLOCK		= 301;
    static const short int SCROLLOCK		= 302;
    static const short int RSHIFT		= 303;
    static const short int LSHIFT		= 304;
    static const short int RCTRL		= 305;
    static const short int LCTRL		= 306;
    static const short int RALT		= 307;
    static const short int LALT		= 308;
    static const short int RMETA		= 309;
    static const short int LMETA		= 310;
    static const short int LSUPER		= 311;		/**< Left "Windows" key */
    static const short int RSUPER		= 312;		/**< Right "Windows" key */
    static const short int MODE		= 313;		/**< "Alt Gr" key */
    static const short int COMPOSE		= 314;		/**< Multi-key compose key */
        /*@}*/

    /** @name Miscellaneous function keys */
        /*@{*/
    static const short int HELP		= 315;
    static const short int PRINT		= 316;
    static const short int SYSREQ		= 317;
    static const short int BREAK		= 318;
    static const short int MENU		= 319;
    static const short int POWER		= 320;		/**< Power Macintosh power key */
    static const short int EURO		= 321;		/**< Some european keyboards */
    static const short int UNDO		= 322;		/**< Atari keyboard has Undo */
};

#endif /* INPUT_H_ */
