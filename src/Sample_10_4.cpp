/*
 * Sample_10_4.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_10_4.h"
#include "OGLShapes.h"
#include "OGLInspector.h"
#include "jitter.h"
#include <cmath>
#include <SDL/SDL.h>

#define PI_ 	3.14159265358979323846
#define ACSIZE	8
#define JITTER	j8

/*	Note that 4.5 is the distance in world space between
 *	left and right and bottom and top.
 *	This formula converts fractional pixel movement to
 *	world coordinates.
 */
#define COORD_DIST	4.5

Sample_10_4::Sample_10_4()
:	m_accDraw(ACSIZE)
{
}

Sample_10_4::~Sample_10_4()
{
}

void Sample_10_4::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho (-(COORD_DIST/2), (COORD_DIST/2), -(COORD_DIST/2)*h/w, (COORD_DIST/2)*h/w, -10.0, 10.0);
	else
		glOrtho (-(COORD_DIST/2)*w/h, (COORD_DIST/2)*w/h, -(COORD_DIST/2), (COORD_DIST/2), -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_10_4::draw()
{
	GLint viewport[4];
	int jitter;

	glGetIntegerv (GL_VIEWPORT, viewport);

	glClear(GL_ACCUM_BUFFER_BIT);
	for (jitter = 0; jitter < m_accDraw; jitter++) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix ();
		glTranslatef (j8[jitter].x*COORD_DIST/viewport[2],
				j8[jitter].y*COORD_DIST/viewport[3], 0.0);
		displayObjects ();
		glPopMatrix ();
		glAccum(GL_ACCUM, 1.0/m_accDraw);
	}
	glAccum (GL_RETURN, 1.0);
}

void Sample_10_4::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.3, 0.0, 0.3, 0.0);
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_FLAT);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearAccum(0.0, 0.0, 0.0, 0.0);
}

void Sample_10_4::restoreGL()
{
	glPopAttrib();
}

bool Sample_10_4::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_a:
		m_accDraw = ACSIZE;
		break;
	case SDLK_n:
		m_accDraw = 1;
		break;
	case SDLK_b:
		OGLInspector::BuffersReport();
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_10_4::displayObjects()
{
	GLfloat torus_diffuse[] = { 0.7, 0.7, 0.0, 1.0 };
	GLfloat cube_diffuse[] = { 0.0, 0.7, 0.7, 1.0 };
	GLfloat sphere_diffuse[] = { 0.7, 0.0, 0.7, 1.0 };
	GLfloat octa_diffuse[] = { 0.7, 0.4, 0.4, 1.0 };

	glPushMatrix ();
	glTranslatef (0.0, 0.0, -5.0);
	glRotatef (30.0, 1.0, 0.0, 0.0);

	glPushMatrix ();
	glTranslatef (-0.80, 0.35, 0.0);
	glRotatef (100.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, torus_diffuse);
	OGLShapes::solidTorus (0.275, 0.85, 16, 16);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (-0.75, -0.50, 0.0);
	glRotatef (45.0, 0.0, 0.0, 1.0);
	glRotatef (45.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
	OGLShapes::solidCube (1.5);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0.75, 0.60, 0.0);
	glRotatef (30.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere_diffuse);
	OGLShapes::solidSphere (1.0, 16, 16);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0.70, -0.90, 0.25);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, octa_diffuse);
	OGLShapes::solidSphere (1.0, 4, 6);
	glPopMatrix ();

	glPopMatrix ();
}
