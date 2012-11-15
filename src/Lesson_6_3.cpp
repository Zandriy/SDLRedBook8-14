/*
 * Lesson_6_3.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_3.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

Lesson_6_3::Lesson_6_3()
: m_rotAngle(0.0)
{
}

Lesson_6_3::~Lesson_6_3() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_3::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height)
		gluOrtho2D (-1.0, 1.0,
				-1.0*(GLfloat)height/(GLfloat)width, 1.0*(GLfloat)height/(GLfloat)width);
	else
		gluOrtho2D (-1.0*(GLfloat)width/(GLfloat)height,
				1.0*(GLfloat)width/(GLfloat)height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_6_3::drawGLScene()
{
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth (1.5);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable (GL_LINE_SMOOTH);
	glDisable (GL_BLEND);
	glLineWidth (0.0);
}

void Lesson_6_3::draw()
{
	glColor3f (0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(-m_rotAngle, 0.0, 0.0, 0.1);
	glBegin (GL_LINES);
	glVertex2f (-0.5, 0.5);
	glVertex2f (0.5, -0.5);
	glEnd ();
	glPopMatrix();

	glColor3f (0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(m_rotAngle, 0.0, 0.0, 0.1);
	glBegin (GL_LINES);
	glVertex2f (0.5, 0.5);
	glVertex2f (-0.5, -0.5);
	glEnd ();
	glPopMatrix();
}

bool Lesson_6_3::sendMessage(int message, int mode, int x, int y)
{
	switch (message)
	{
	case SDLK_r:
		m_rotAngle += 20.;
		if (m_rotAngle >= 360.) m_rotAngle = 0.;
		GLfloat values[2];
		glGetFloatv (GL_LINE_WIDTH_GRANULARITY, values);
		printf ("GL_LINE_WIDTH_GRANULARITY value is %3.1f\n", values[0]);

		glGetFloatv (GL_LINE_WIDTH_RANGE, values);
		printf ("GL_LINE_WIDTH_RANGE values are %3.1f %3.1f\n",
				values[0], values[1]);
		break;
	default:
		return false;
		break;
	}

	return true;
}
