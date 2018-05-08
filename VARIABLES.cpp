#include "includesVoids.h"
//GLOBALS
	bool INIT_=true;//this is the only variable to initialize in the VARIABLES.cpp file;
	//LISTS: 
		GLint board=1,boardHalf=2,boardFourth=3,boardColor=4,boardColorHalf=5;
		GLint players[8]={20,21,22,23,24,25,26,27};
	//STRUCT:
		_BUTTONS BUTTON[44];
			int buttonSelected;
		_PLAYER PLAYER[8];
		_PROPERTIES PROPERTY[28];
		_CARDS CARDS;
		_BANK BANK;
		_BOARD BOARD[45];
	//WINDOW: 
		double winW,winH;
		double aspect;
		bool fullScreen=false;//and this one;
