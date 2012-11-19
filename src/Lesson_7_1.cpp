/*
 * Lesson_7_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_7_1.h"

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

Lesson_7_1::Lesson_7_1()
: m_theTorus(0)
{
}

Lesson_7_1::~Lesson_7_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_7_1::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLfloat) width/(GLfloat) height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void Lesson_7_1::drawGLScene()
{
	if (!m_theTorus)
	{
		m_theTorus = glGenLists (1);
		glNewList(m_theTorus, GL_COMPILE);
		torus(8, 25);
		glEndList();
	}
	glShadeModel(GL_FLAT);

	draw();

	glShadeModel(GL_SMOOTH);
}

void Lesson_7_1::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glCallList(m_theTorus);
}

bool Lesson_7_1::sendMessage(int message, int mode, int x, int y)
{
	switch (message)
	{
	case SDLK_x:
		glRotatef(30.,1.0,0.0,0.0);
		break;
	case SDLK_y:
		glRotatef(30.,0.0,1.0,0.0);
		break;
	case SDLK_i:
		glLoadIdentity();
		gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Lesson_7_1::torus(int numc, int numt)
{
	int i, j, k;
	double s, t, x, y, z, twopi;

	twopi = 2 * (double)M_PI;
	for (i = 0; i < numc; i++) {
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= numt; j++) {
			for (k = 1; k >= 0; k--) {
				s = (i + k) % numc + 0.5;
				t = j % numt;

				x = (1+.1*cos(s*twopi/numc))*cos(t*twopi/numt);
				y = (1+.1*cos(s*twopi/numc))*sin(t*twopi/numt);
				z = .1 * sin(s * twopi / numc);
				glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
}
