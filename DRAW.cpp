#include "includesVoids.h"
void DRAW3D(){//http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-9-vbo-indexing/
	LISTS();	
		double tempX=0;
		double tempY=0;
		double tempTX=0;
		double tempTY=0;
		bool worthColor=false;
//	
	for(int n=0;n<45;n++){
		glLoadIdentity();
		//board location values: 
			if(n==0){			tempX=5.5;tempY=-5.5;}
			else if(n==1)		tempX-=1.5;
			else if(n<10)		tempX-=1;
			else if(n==10)		tempX-=1.5;
				else if(n==11)		tempY+=1.5;
				else if(n<20)		tempY+=1;
				else if(n==20)		tempY+=1.5;
			else if(n==21)		tempX+=1.5;
			else if(n<30)		tempX+=1;
			else if(n==30)		tempX+=1.5;
				else if(n==31)		tempY-=1.5;
				else if(n<40)		tempY-=1;
				else if(n==40){		tempX=-5;tempY=-5;}
			else if(n==41){		tempX=-2.75;tempY=2.75;}
			else if(n==42){		tempX=2.75;tempY=-2.75;}
			else if(n==43){		tempX=-3.5;tempY=-4;}
		glTranslatef(tempX,tempY,-16);//-19
		//call the lists: 
			if(n==0)			glCallList(board);
			else if(n<10){		glCallList(boardHalf);}
			else if(n==10){		glCallList(board);}
				else if(n<20){		glRotatef(90,0,0,1);glCallList(boardHalf);}
				else if(n==20){		glCallList(board);}
			else if(n<30){		glCallList(boardHalf);}
			else if(n==30){		glCallList(board);}
				else if(n<40){		glRotatef(90,0,0,1);glCallList(boardHalf);}
				else if(n==40)		glCallList(boardFourth);//jail;
			else if(n==41){		glRotatef(-45,0,0,1);glCallList(boardHalf);}
			else if(n==42){		glRotatef(-45,0,0,1);glCallList(boardHalf);}
				else if(n==43){		glRotatef(90,0,0,1);glCallList(boardHalf);}//cash pile;
		//colors for board: 
			if(n==1||n==3){			glTranslatef(-.25,0,0);glColor4f(0.5,0.35,0.05,.5);glCallList(boardColorHalf);}
			if(n==6||n==8||n==9){	glTranslatef(-.25,0,0);glColor4f(.5,.75,.6,.5);glCallList(boardColorHalf);}
			if(n==11||n==13||n==14){glTranslatef(.25,0,0);glColor4f(.6,.2,.4,.5);glCallList(boardColorHalf);}
			if(n==16||n==18||n==19){glTranslatef(.25,0,0);glColor4f(.85,.6,0,.5);glCallList(boardColorHalf);}
			if(n==21||n==23||n==24){glTranslatef(.25,0,0);glColor4f(.8,0,0,.5);glCallList(boardColorHalf);}
			if(n==26||n==27||n==29){glTranslatef(.25,0,0);glColor4f(.9,.9,0,.5);glCallList(boardColorHalf);}
			if(n==31||n==32||n==34){glTranslatef(.25,0,0);glColor4f(0,.7,.2,.5);glCallList(boardColorHalf);}
			if(n==37||n==39){		glTranslatef(.25,0,0);glColor4f(0,.2,.7,.5);glCallList(boardColorHalf);}
		//railroads: 
			if(n==5){				glTranslatef(-.25,0,0);glColor4f(.3,.2,.2,.5);glCallList(boardColorHalf);}
			if(n==15||n==25||n==35){glTranslatef(.25,0,0);glColor4f(.3,.2,.2,.5);glCallList(boardColorHalf);}
		//utilities: 
			if(n==12||n==28){		glTranslatef(.25,0,0);glColor4f(.6,.5,.6,.5);glCallList(boardColorHalf);}
		//chance/community chest: 
			if(n==2||n==7){			glTranslatef(-.25,0,0);glColor4f(.9,.8,.4,.5);glCallList(boardColorHalf);}
			if(n==17||n==22){		glTranslatef(.25,0,0);glColor4f(.9,.8,.4,.5);glCallList(boardColorHalf);}
			if(n==33||n==36){		glTranslatef(.25,0,0);glColor4f(.9,.8,.4,.5);glCallList(boardColorHalf);}
		//pay taxes: 
			if(n==4){				glTranslatef(-.25,0,0);glColor4f(.05,.05,.05,.5);glCallList(boardColorHalf);}
			if(n==38){				glTranslatef(.25,0,0);glColor4f(.05,.05,.05,.5);glCallList(boardColorHalf);}
		//extra center spots and money value in free parking spot: 	
			if(n==41||n==42||n==43){glColor4f(.9,.8,.4,.5);glCallList(boardColor);}
		//get player positions: 
			for(int m=0;m<8;m++){
				if(PLAYER[m].position==n){
					PLAYER[m].XPos=tempX;
					PLAYER[m].YPos=tempY;
				}
			}
		//text stuff and set text values: 
			if(n==44){tempX=-.5;tempY=-.5;}//special for center text: 
			tempTX=-.95;tempTY=.3;
			worthColor=false;//the green for money;
		for(int m=0;m<BOARD[n].text.length();m++){
			glLoadIdentity();
			glColor3f(1,1,1);
		//conditions: 
			if(BOARD[n].text[m]=='\n'){tempTX=-1.05/*-.55*/;tempTY-=.225/*.15*/;}//end line;
			if(BOARD[n].text[m]=='\t'){tempTX+=.35/*.3*/;}//tab
		//initial translation: 
			glTranslatef(tempX,tempY,-16);//-19
		//rotations: 
			glRotatef(BOARD[n].rotation,0,0,1);
		//final translation: 
			glTranslatef(tempTX,tempTY,0);
		//scaling: 
			if(n==44)	glScalef(.003125,.003125,.003125);
			else		glScalef(.0015,.0015,1);
		//increment value: 
			tempTX+=.13;
		//color: 
			if(	BOARD[n].text[m]=='M'&&BOARD[n].text[m+1]=='$'||
				BOARD[n].text[m]=='1'&&BOARD[n].text[m+1]=='0'&&BOARD[n].text[m+2]=='%'
			)worthColor=true;
			else if(	BOARD[n].text[m]=='A'&&BOARD[n].text[m+1]=='S'||
						BOARD[n].text[m]=='o'&&BOARD[n].text[m+1]=='r'
			)worthColor=false;

			if(worthColor==false)glColor3f(1,1,1);
			else glColor3f(.2,.75,.2);
		//draw text: 
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,BOARD[n].text[m]);
		}
	}
	//draw players:
	double incrX=0,incrY=0;
	for(int m=0;m<8;m++){
		glLoadIdentity();
		//initial translate: 
			glTranslatef(PLAYER[m].XPos,PLAYER[m].YPos,-16);
		//subpositions: 
		if(PLAYER[m].position<10){
			if(PLAYER[m].position==0){glTranslatef(.615,-1.1125,0);}
			else if(PLAYER[m].position<10){glTranslatef(.125,-1.1125,0);}
			if(m%2==0){incrX=0;incrY+=.25;}
			glTranslatef(incrX,incrY,0);
			incrX+=.25;
		}
		else if(PLAYER[m].position<20){
			if(PLAYER[m].position==10){glTranslatef(-1.1125,-0.6025,0);}
			else if(PLAYER[m].position<20){glTranslatef(-1.1125,-0.1125,0);}
			if(m%2==0){incrX+=.25;incrY=0;}
			glTranslatef(incrX,incrY,0);
			incrY-=.25;
		}
		else if(PLAYER[m].position<30){
			if(PLAYER[m].position==20){glTranslatef(-0.6215,1.1125,0);}
			else if(PLAYER[m].position<30){glTranslatef(-.125,1.1125,0);}
			if(m%2==0){incrX=0;incrY-=.25;}
			glTranslatef(incrX,incrY,0);
			incrX-=.25;
		}
		else if(PLAYER[m].position<40){
			if(PLAYER[m].position==30){glTranslatef(-.87,-.87,0);}
			else if(PLAYER[m].position<40){glTranslatef(1.1375,-0.3625,0);}
			if(PLAYER[m].position!=30){
				if(m%2==0){incrX-=.25;incrY=0;}
				glTranslatef(incrX,incrY,0);
				incrY+=.25;
			}
		}
		else if(PLAYER[m].position==40){
			if(m==0)		glTranslatef(-0.12375,0.37625,0);
			else if(m<4)	glTranslatef(-0.37375,0.37625-(.25*(m-1)),0);
			else if(m<7) 	glTranslatef(-1.12375+(.25*m),-0.37375,0);
			else			glTranslatef(0.37625,-0.12375,0);
		}
		//color: 
			glColor3f(0,m*.125,m*.125);
			if(m==0)glColor3f(1,0,0);
		//draw: 
			glCallList(players[m]);
	}
}
void DRAW2D(){ 
}
