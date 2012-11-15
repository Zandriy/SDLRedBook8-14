/*
 * Lesson_6_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_1.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>

Lesson_6_1::Lesson_6_1()
: m_leftFirst(true)
{
	// TODO Auto-generated constructor stub
}

Lesson_6_1::~Lesson_6_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_1::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height)
		gluOrtho2D (0.0, 1.0, 0.0, 1.0*(GLfloat)height/(GLfloat)width);
	else
		gluOrtho2D (0.0, 1.0*(GLfloat)width/(GLfloat)height, 0.0, 1.0);
}

void Lesson_6_1::drawGLScene()
{
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel (GL_FLAT);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_BLEND);
	glShadeModel (GL_SMOOTH);
}

void Lesson_6_1::draw()
{
	if(m_leftFirst)
	{
		drawLeftTriangle();
		drawRightTriangle();
	}
	else {
		drawRightTriangle();
		drawLeftTriangle();
	}
}

void Lesson_6_1::drawLeftTriangle()
{
	/* draw yellow triangle on LHS of screen */
	glBegin (GL_TRIANGLES);
	glColor4f(1.0, 1.0, 0.0, 0.75);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();
}

void Lesson_6_1::drawRightTriangle()
{
	/* draw cyan triangle on RHS of screen */
	glBegin (GL_TRIANGLES);
	glColor4f(0.0, 1.0, 1.0, 0.75);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glEnd();
}


bool Lesson_6_1::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_t:
		m_leftFirst = !m_leftFirst;
		break;
	default:
		return false;
		break;
	}

	return true;
}
