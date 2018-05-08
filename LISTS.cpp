#include "includesVoids.h"
void LISTS(){
		glGenLists(board);
		glNewList(board,GL_COMPILE);
			glColor3f(1,0,1);
			glBegin(GL_LINE_LOOP);	
				glVertex2f(1.f, 1.f);//.25;
		    	glVertex2f(1.f, -1.f);//.25;
		    	glVertex2f(-1.f, -1.f);//.25;
		    	glVertex2f(-1.f, 1.f);//.25;
			glEnd();
		glEndList();
		glGenLists(boardHalf);
		glNewList(boardHalf,GL_COMPILE);
			glColor3f(1,0,1);
			glBegin(GL_LINE_LOOP);	
				glVertex2f(1.f/2, 1.f);//.25;
		    	glVertex2f(1.f/2, -1.f);//.25;
		    	glVertex2f(-1.f/2, -1.f);//.25;
		    	glVertex2f(-1.f/2, 1.f);//.25;
			glEnd();
		glEndList();
		glGenLists(boardFourth);
		glNewList(boardFourth,GL_COMPILE);
			glColor3f(1,0,1);
			glBegin(GL_LINE_LOOP);	
				glVertex2f(1.f/2, 1.f/2);//.25;
		    	glVertex2f(1.f/2, -1.f/2);//.25;
		    	glVertex2f(-1.f/2, -1.f/2);//.25;
		    	glVertex2f(-1.f/2, 1.f/2);//.25;
			glEnd();
		glEndList();//
		glGenLists(boardColor);
		glNewList(boardColor,GL_COMPILE);
			//glColor3f(1,0,1);
			glBegin(GL_POLYGON);	
				glVertex2f(1.f/2, 1.f);//.25;
		    	glVertex2f(1.f/2, -1.f);//.25;
		    	glVertex2f(-1.f/2, -1.f);//.25;
		    	glVertex2f(-1.f/2, 1.f);//.25;
			glEnd();
		glEndList();
		glGenLists(boardColorHalf);
		glNewList(boardColorHalf,GL_COMPILE);
			//glColor3f(1,0,1);
			glBegin(GL_POLYGON);	
				glVertex2f(1.f/4, 1.f);//.25;
		    	glVertex2f(1.f/4, -1.f);//.25;
		    	glVertex2f(-1.f/4, -1.f);//.25;
		    	glVertex2f(-1.f/4, 1.f);//.25;
			glEnd();
		glEndList();
		for(int n=0;n<8;n++){
			glGenLists(players[n]);
			glNewList(players[n],GL_COMPILE);
				//glColor3f(1,0,1);
				glBegin(GL_POLYGON);	
					glVertex2f(1.f/8, 1.f/8);//.25;
			    	glVertex2f(1.f/8, -1.f/8);//.25;
			    	glVertex2f(-1.f/8, -1.f/8);//.25;
			    	glVertex2f(-1.f/8, 1.f/8);//.25;
				glEnd();
			glEndList();
		}
}
