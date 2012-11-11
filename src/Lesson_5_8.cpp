/*
 * Lesson_5_8.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_8.h"

#include "OGLShapes.h"

Lesson_5_8::Lesson_5_8()
{
	// TODO Auto-generated constructor stub
}

Lesson_5_8::~Lesson_5_8() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_8::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width<=height)
		glOrtho(-1.5,1.5,-1.5*(GLfloat)height/(GLfloat)width, 1.5*(GLfloat)height/(GLfloat)width,-10.0,10.0);
	else
		glOrtho(-1.5*(GLfloat)width/(GLfloat)height, 1.5*(GLfloat)width/(GLfloat)height,-1.5,1.5,-10.0,10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_8::drawGLScene()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);

	//Set the light
	GLfloat light_position[]={1.0,1.0,1.0,0.0};
	GLfloat light_position1[]={0.0,0.0,0.0,0.0};
	GLfloat white_light[]={1.0,1.0,1.0,1.0};
	GLfloat grey_light[]={0.3,0.3,0.3,0.5};

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);

	glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,grey_light);
	glLightfv(GL_LIGHT1,GL_SPECULAR,grey_light);

	//...and model of two side lighting
	GLfloat lmodel_ambient[]={1.0,1.0,1.0,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	//Switch on the necessary things
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);

	//Set material for facĕ
	GLfloat mat_specular_front[]={0.0,0.3,0.9,1.0};
	GLfloat mat_ambient_front[]={0.0,0.1,0.3,1.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular_front);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient_front);

	//... and for back
	GLfloat mat_specular_back[]={1.0,0.0,0.0,1.0};
	GLfloat mat_ambient_back[]={0.5,0.1,0.1,1.0};
	glMaterialfv(GL_BACK,GL_SPECULAR,mat_specular_back);
	glMaterialfv(GL_BACK,GL_AMBIENT,mat_ambient_back);

	//GL_SHININESS is the same for both sides in this casĕ
	GLfloat mat_shininess[]={50.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

	//Set the plain of cutting
	GLdouble equation[]={0.4,0.5,-0.5,0.6};
	glClipPlane(GL_CLIP_PLANE1, equation);
	glEnable(GL_CLIP_PLANE1);

	//Set which sides are face
	glFrontFace(GL_CW);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	//Set defaults
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_CLIP_PLANE1);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glFrontFace(GL_CCW);

	GLfloat lmodel_ambientSET_DEFAULT[]={0.2,0.2,0.2,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambientSET_DEFAULT);
}

void Lesson_5_8::draw()
{
	OGLShapes::solidSphere(0.85, 15, 25);
}
