/*
 * Lesson_6_7.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_7.h"

#include "OGLShapes.h"

Lesson_6_7::Lesson_6_7()
{
	// TODO Auto-generated constructor stub
}

Lesson_6_7::~Lesson_6_7() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_7::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	      glOrtho (-2.0, 2.0, -1.0, 1.0, -10.0, 10.0);
	   glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_6_7::drawGLScene()
{
	GLfloat mat_specular[] = { 1.0, 0.0, 0.3, 1.0 };
	GLfloat light_position[] = { 1.0, 3.0, 5.0, 0.0 };

	// directional light
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);

	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(30.0,1.0,1.0,0.0);
	draw();
	glPopMatrix();

	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0,1.0);
	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(30.0,1.0,1.0,0.0);
	draw();
	glPopMatrix();
	glDisable(GL_POLYGON_OFFSET_FILL);

	glDisable(GL_DEPTH_TEST);
}

void Lesson_6_7::draw()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	OGLShapes::solidTorus(0.275,1.0,20,20);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glColor3f(1.0,1.0,1.0);
	OGLShapes::wireTorus(0.275,1.0,40,40);
}
