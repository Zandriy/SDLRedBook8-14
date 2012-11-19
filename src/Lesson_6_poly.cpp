/*
 * Lesson_6_poly.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_poly.h"

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#define NFACE 6
#define NVERT 8

Lesson_6_poly::Lesson_6_poly()
: m_polySmooth(GL_FALSE)
{
}

Lesson_6_poly::~Lesson_6_poly() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_poly::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(12.0, (GLfloat) width/(GLfloat) height, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_6_poly::drawGLScene()
{
	glCullFace (GL_BACK);
	glEnable (GL_CULL_FACE);
	// here is problem with GL_SRC_ALPHA_SATURATE,
	// most probably because of double buffering
	glBlendFunc (GL_SRC_ALPHA_SATURATE, GL_ONE);
	glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);

	draw();

	glDisable (GL_CULL_FACE);
	glDisable (GL_BLEND);
	glDisable (GL_DEPTH_TEST);
}

void Lesson_6_poly::draw()
{
	if (m_polySmooth) {
		glClear (GL_COLOR_BUFFER_BIT);
		glEnable (GL_BLEND);
		glEnable (GL_POLYGON_SMOOTH);
		glDisable (GL_DEPTH_TEST);
	}
	else {
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable (GL_BLEND);
		glDisable (GL_POLYGON_SMOOTH);
		glEnable (GL_DEPTH_TEST);
	}

	glPushMatrix ();
	glTranslatef (0.0, 0.0, -8.0);
	glRotatef (30.0, 1.0, 0.0, 0.0);
	glRotatef (60.0, 0.0, 1.0, 0.0);
	drawCube(-0.5, 0.5, -0.5, 0.5, -0.5, 0.5);
	glPopMatrix ();
}

bool Lesson_6_poly::sendMessage(int message, int mode, int x, int y)
{
	switch (message)
	{
	case SDLK_t:
		m_polySmooth = !m_polySmooth;
		if (m_polySmooth)
			printf ("Poly is smooth.\n");
		else
			printf ("Poly is not smooth.\n");
		break;
		drawGLScene();
	default:
		return false;
		break;
	}

	return true;
}

void Lesson_6_poly::drawCube(GLdouble x0, GLdouble x1, GLdouble y0, GLdouble y1,
		GLdouble z0, GLdouble z1)
{
	static GLfloat v[8][3];
	static GLfloat c[8][4] = {
			{0.0, 0.0, 0.0, 0.95}, {1.0, 0.0, 0.0, 0.95},
			{0.0, 1.0, 0.0, 0.95}, {1.0, 1.0, 0.0, 0.95},
			{0.0, 0.0, 1.0, 0.95}, {1.0, 0.0, 1.0, 0.95},
			{0.0, 1.0, 1.0, 0.95}, {1.0, 1.0, 1.0, 0.95}
	};

	/*  indices of front, top, left, bottom, right, back faces  */
	static GLubyte indices[NFACE][4] = {
			{4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3},
			{0, 1, 5, 4}, {1, 5, 6, 2}, {0, 3, 2, 1}
	};

	v[0][0] = v[3][0] = v[4][0] = v[7][0] = x0;
	v[1][0] = v[2][0] = v[5][0] = v[6][0] = x1;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = y0;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = y1;
	v[0][2] = v[1][2] = v[2][2] = v[3][2] = z0;
	v[4][2] = v[5][2] = v[6][2] = v[7][2] = z1;

#ifdef GL_VERSION_1_1
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_COLOR_ARRAY);
	glVertexPointer (3, GL_FLOAT, 0, v);
	glColorPointer (4, GL_FLOAT, 0, c);
	glDrawElements (GL_QUADS, NFACE*4, GL_UNSIGNED_BYTE, indices);
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_COLOR_ARRAY);
#else
	printf ("If this is GL Version 1.0, ");
	printf ("vertex arrays are not supported.\n");
#endif
}
