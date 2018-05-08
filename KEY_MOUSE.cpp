#include "includesVoids.h"
void mousemoveunpressed(int x, int y){
}//end void;
void mousemotion(int x, int y){
}
void mouseclick(int button, int state, int x, int y){
	//buttons: 
	if(state==GLUT_UP){//MOUSE RELEASE FROM BUTTON: 
		for(int n=0;n<25;n++){//button collision: 
			if(x>BUTTON[n].x&&x<(BUTTON[n].x+BUTTON[n].width)&&y>BUTTON[n].y&&y<(BUTTON[n].y+BUTTON[n].height)){
				BUTTON_LOGIC(n);
				break;
			}
		}
	}
}//end void;
void skeyd (int key, int x, int y){
}//end void;
void keyPressed(unsigned char key, int x, int y){//glutKeyboardFunc(keyPressed);
	for(int n=0;n<8;n++){
		if(key=='a')PLAYER[n].position+=1;
		if(key=='s')PLAYER[n].position-=1;
		if(PLAYER[n].position>40||PLAYER[n].position<0)PLAYER[n].position=0;
	}
}//end void;
