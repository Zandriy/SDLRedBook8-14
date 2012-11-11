/*
 * Lesson_5_9.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_9.h"

#include "OGLShapes.h"

Lesson_5_9::Lesson_5_9()
{
	// TODO Auto-generated constructor stub
}

Lesson_5_9::~Lesson_5_9() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_9::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-5.0,5.0,-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_9::drawGLScene()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);

	GLfloat light_position[]={1.0,1.0,1.0,0.0};
	GLfloat white_light[]={1.0,1.0,1.0,1.0};

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
}

void Lesson_5_9::draw()
{
	GLfloat no_mat[]={0.0,0.0,0.0,1.0};
	GLfloat mat_ambient[]={0.7,0.7,0.7,1.0};
	GLfloat mat_ambient_color[]={0.8,0.8,0.2,1.0};
	GLfloat mat_diffuse[]={0.1,0.5,0.8,1.0};
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat no_shininess[]={0.0};
	GLfloat low_shininess[]={5.0};
	GLfloat high_shininess[]={100.0};
	GLfloat mat_emission[]={0.3,0.2,0.2,0.0};

	//Draw first sphere
	glPushMatrix();
	glTranslatef(-3.75,0.0,0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	OGLShapes::solidSphere(1.0,16,16);
	glPopMatrix();

	//Draw second sphere
	glPushMatrix();
	glTranslatef(-1.25,0.0,0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	OGLShapes::solidSphere(1.0,16,16);
	glPopMatrix();

	//Draw third sphere
	glPushMatrix();
	glTranslatef(1.25,0.0,0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	OGLShapes::solidSphere(1.0,16,16);
	glPopMatrix();

	//Draw forth sphere
	glPushMatrix();
	glTranslatef(3.75,0.0,0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	OGLShapes::solidSphere(1.0,16,16);
	glPopMatrix();
}
