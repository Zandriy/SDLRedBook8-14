/*
 * Sample_10_1.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_10_1.h"
#include "OGLShapes.h"

#define YELLOWMAT   1
#define BLUEMAT 2

Sample_10_1::Sample_10_1()
{
}

Sample_10_1::~Sample_10_1()
{
}

void Sample_10_1::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	/* create a diamond shaped stencil area */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-3.0, 3.0, -3.0*(GLfloat)h/(GLfloat)w,
				3.0*(GLfloat)h/(GLfloat)w);
	else
		gluOrtho2D(-3.0*(GLfloat)w/(GLfloat)h,
				3.0*(GLfloat)w/(GLfloat)h, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_STENCIL_BUFFER_BIT);
	glStencilFunc (GL_ALWAYS, 0x1, 0x1);
	glStencilOp (GL_REPLACE, GL_REPLACE, GL_REPLACE);
	glBegin(GL_QUADS);
		glVertex2f (-1.0, 0.0);
		glVertex2f (0.0, 1.0);
		glVertex2f (1.0, 0.0);
		glVertex2f (0.0, -1.0);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 3.0, 7.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void Sample_10_1::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* draw blue sphere where the stencil is 1 */
	glStencilFunc (GL_EQUAL, 0x1, 0x1);
	glStencilOp (GL_KEEP, GL_KEEP, GL_KEEP);
	glCallList (BLUEMAT);
	OGLShapes::solidSphere (0.5, 15, 15);

	/* draw the torus where the stencil is not 1 */
	glStencilFunc (GL_NOTEQUAL, 0x1, 0x1);
	glPushMatrix();
	glRotatef (45.0, 0.0, 0.0, 1.0);
	glRotatef (45.0, 0.0, 1.0, 0.0);
	glCallList (YELLOWMAT);
	OGLShapes::solidTorus (0.275, 0.85, 15, 15);
		glPushMatrix();
		glRotatef (90.0, 1.0, 0.0, 0.0);
		OGLShapes::solidTorus (0.275, 0.85, 15, 15);
		glPopMatrix();
	glPopMatrix();
}

void Sample_10_1::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	GLfloat yellow_diffuse[] = { 0.7, 0.7, 0.0, 1.0 };
	GLfloat yellow_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat blue_diffuse[] = { 0.1, 0.1, 0.7, 1.0 };
	GLfloat blue_specular[] = { 0.1, 1.0, 1.0, 1.0 };

	GLfloat position_one[] = { 1.0, 1.0, 1.0, 0.0 };

	glNewList(YELLOWMAT, GL_COMPILE);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, yellow_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 64.0);
	glEndList();

	glNewList(BLUEMAT, GL_COMPILE);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blue_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 45.0);
	glEndList();

	glLightfv(GL_LIGHT0, GL_POSITION, position_one);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glClearStencil(0x0);
	glEnable(GL_STENCIL_TEST);
}

void Sample_10_1::restoreGL()
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);

	glPopAttrib();
}
