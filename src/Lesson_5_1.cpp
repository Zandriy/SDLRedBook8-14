/*
 * Lesson_5_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_1.h"

#include "OGLShapes.h"

Lesson_5_1::Lesson_5_1() {
	// TODO Auto-generated constructor stub
}

Lesson_5_1::~Lesson_5_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_1::reshape(int width, int height)
{
	   glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	   glMatrixMode (GL_PROJECTION);
	   glLoadIdentity();
	   if (width <= height)
	      glOrtho (-1.5, 1.5, -1.5*(GLfloat)height/(GLfloat)width,
	         1.5*(GLfloat)height/(GLfloat)width, -10.0, 10.0);
	   else
	      glOrtho (-1.5*(GLfloat)width/(GLfloat)height,
	         1.5*(GLfloat)width/(GLfloat)height, -1.5, 1.5, -10.0, 10.0);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
}

void Lesson_5_1::drawGLScene()
{
	GLfloat mat_specular[] = { 1.0, 0.7, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 }; // 0.0 ... 128.0
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_ambient1[]={1.0, 0.2, 0.2, 1.0};
	GLfloat light_diffuse1[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular1[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_position1[]={-0.2, -0.2, 1.0, 1.0};
	GLfloat spot_direction1[]={-1.0, -1.0, 0.0};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	// directional light
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);

	// positional light ( spot )
	glLightfv(GL_LIGHT1,GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1,GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1,GL_POSITION, light_position1);
	glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION, 0.5);
	glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION, 0.2);
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION, spot_direction1);
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT, 2.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}


void Lesson_5_1::draw()
{
	OGLShapes::solidSphere (1.0, 20, 16);
}
