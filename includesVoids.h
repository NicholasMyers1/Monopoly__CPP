#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
		#include <future>
		#include <math.h>
		#include <ctime>
		#ifdef WIN32
			#define WIN32_LEAN_AND_MEAN
			#include <windows.h>
		#endif
		#include <iostream>
		#include <stdlib.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <cstring>
		#include <fstream>
	#define GLEW_STATIC
		#include <GL/glew.h>
		#include <gl\gl.h>
		#include <gl\glext.h>
		#include <gl\glaux.h>
		#include <gl\glu.h>
		#include <GL\glut.h>
		#include <assert.h>
		#include <sstream>
		#include <iomanip>
		#include <ctime>
		#include <cstring>
		#include <cmath>
		#include <limits.h>
		#include <random>
		#include <fstream>
		#include <time.h>
		#include <string.h>
		#include <string>
		#include <cstdlib>
		#include <cstdio>
		#include <gl\glfw.h>
		#include <vector>
		#include <conio.h>
		#include <new>
	using namespace std;
/*
-lglew32s
-lglut32
-lglu32
-lwinmm
-lgdi32
-lmingw32
-lopengl32
*/
	//DEFINITIONS: 
	//VOIDS: 
		void INIT();
			void BUTTON_LOGIC(int buttonNumber);
			void mousemoveunpressed(int x, int y);
			void mousemotion(int x, int y);
			void mouseclick(int button,int state,int x,int y);
			void skeyd (int key,int x,int y);
			void keyPressed(unsigned char key,int x,int y);
			void LISTS();
		void DRAW2D();
		void DRAW3D();
	//LISTS: 
		extern GLint board,boardHalf,boardFourth,boardColor,boardColorHalf;
		extern GLint players[8];
	//STRUCTURES:
		//buttons; 
		struct _BUTTONS{
			double x,y;
			double width,height;
			string text;
		};extern _BUTTONS BUTTON[44];
		extern int buttonSelected;
//
		struct _BOARD{
			string text;//for position 43: collect money in middle for free parking;
			//int type;//buyable(1) community chest(2) chance(3) tax(10% or 200)(4) tax 75(5) just visiting(6) freeparking(7) utiltiy(8) gotojail(9) go(10) jail(11) 
			//int xPos;//used for player to access x position;
			//int yPos;//used for player to access y position;
			int rotation;//left, right, up, down for text and position on board;
		};extern _BOARD BOARD[45];//accessed using position of player;//45 is text in middle;
//
		struct _BANK{
			int balance;
			//bool propertyCurrentlyOwned[28];//owned by player or bank;0=bank; 1=player;
			int housesLeft;//number of houses left: 12 init;
			int hotelsLeft;//number of hotels left: 33 init;
			int dice[2];//die 1 and die 2;
		};extern _BANK BANK;
//
		struct _PROPERTIES{
			string propertyName;//string name;
			int propertyGroup;//group number;
			int propertyGroupSize;//group size;
			int propertyPosition;//position on board and id;
    		int priceBuy;//price to buy the property;
    		int houseCost;//hotel cost;
			int hotelCost;//house cost;
			int priceMortgage;//mortgage cost;
			int priceUnmortgage;//mortgage cost + 10%
			int rent[7];//the rent levels;
			int currentRentLevel;//the current access element for the rent price; ex: PROPERTY[n].rent[PROPERTY[n].currentRent];
			int owner;//the current owner; -1=bank;
			bool mortgaged;//mortgaged or not?
		};extern _PROPERTIES PROPERTY[28];//all properties;
//
		struct _CARDS{
			struct _COMMUNITYCHEST{
				int type;
				int value[2];
				string text;
			};_COMMUNITYCHEST COMMUNITYCHEST[16];
			struct _CHANCE{
				int type;
				int value[2];
				string text;
			};_CHANCE CHANCE[16];
		};extern _CARDS CARDS;
//
		struct _PLAYER{
			int position;//position on board;
			int positionPrev;//used for knowing if player passed go or not for the extra 200;
			double XPos,YPos;//actual x/y coordinate on board;
			int balanceTotal;//the current balance of the player;
			bool getOutOfJailCommunityChestCard;
			bool getOutOfJailChanceCard;
			int payment;//the amount of the current transaction;
			bool inJail;//in jail or not?
			short unsigned int jailTurns;//turns for injail;
			//int propertyCurrentlyOwned[28];//number of properties owned; the value is: PLAYER[n].propertyCurrentlyOwned[nSize-1]=PLAYER[n].position; if one buys, it will be on the current position;
			bool bankrupt;//in the game or not?
			struct _TRADING{
				bool trading;
				int cashReceive;
				bool propertyReceive[28];
				bool tradeGetOutOfJailCardReceive[2];
				int cashGive;
				bool propertyGive[28];
				bool tradeGetOutOfJailCardGive[2];
			};_TRADING TRADING;
		};extern _PLAYER PLAYER[8];
	//GLOBALS: 
		extern bool INIT_;
		//WINDOW: 
			extern double winW,winH;
			extern double aspect;
			extern bool fullScreen;
#endif
