#include "includesVoids.h"
void display(){
	//3d for stuff in window: 
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
	//	glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if(winH!=0)gluPerspective(45.f,(float)winW/winH, 0.1, 10000.0);//(3.14f/*145.f*//*90.f*/,winW/winH,.1f,100.f);
		glMatrixMode(GL_MODELVIEW);
		glDepthFunc(GL_LEQUAL);glClearDepth(1);/**/
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glClearColor(.25,.25,.25,.25);//1,1,1,0);//glLoadIdentity();
		//glEnable(GL_CULL_FACE);
		//glEnable(GL_CULL_FACE);glCullFace(GL_FRONT_AND_BACK);
			DRAW3D();
	//2d for buttons: 
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
			glEnable(GL_BLEND);glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0,winW,winH,0,-1,1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
			DRAW2D();
	glutSwapBuffers();
	//test: 
	fullScreen=true;
	if(fullScreen==false){
		glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/1.25,glutGet(GLUT_SCREEN_HEIGHT)/1.25);
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH)-glutGet(GLUT_SCREEN_WIDTH)/1.25)/2,(glutGet(GLUT_SCREEN_HEIGHT)-glutGet(GLUT_SCREEN_HEIGHT)/1.25)/2);
	}
	//else glutFullScreen();
}//end void;
void reshape(int w,int h){
	winW=w;
	winH=h;
		INIT(); 
glMatrixMode(GL_PROJECTION);glLoadIdentity();
glViewport(0,0,w,h);
gluPerspective(60.f,(GLfloat)w/(GLfloat)h,0.01f,256.0f);
//gluPerspective(45.f,(GLfloat)w/(GLfloat)h,0.0f,1800.0f); 
glMatrixMode(GL_MODELVIEW);glLoadIdentity();
}//end void;
int main(int argc,char **argv){//main and set window properties;
    glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/1.25,glutGet(GLUT_SCREEN_HEIGHT)/1.25);
    	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-glutGet(GLUT_SCREEN_WIDTH)/1.25)/2,(glutGet(GLUT_SCREEN_HEIGHT)-glutGet(GLUT_SCREEN_HEIGHT)/1.25)/2);
		glutCreateWindow("SHAPES");
   			glutPassiveMotionFunc(mousemoveunpressed);
   			glutMotionFunc(mousemotion);
    		glutDisplayFunc(display);glutIdleFunc(display);
    		glutReshapeFunc(reshape);
    		glutKeyboardFunc(keyPressed);
    		glutSpecialFunc(skeyd);
    		glutMouseFunc(mouseclick);
	glewInit();
    glutMainLoop();
    return 0;
}
