/*
 * Lesson_6_5.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_5.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>
#include <stdlib.h>

Lesson_6_5::Lesson_6_5()
: m_fogMode(GL_EXP)
{
}

Lesson_6_5::~Lesson_6_5() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_5::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (-2.5, 2.5, -1.0, 0.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
}

void Lesson_6_5::drawGLScene()
{
	GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };

	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	{
		GLfloat mat[3] = {0.1745, 0.01175, 0.01175};
		glMaterialfv (GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat);
		glMaterialf (GL_FRONT, GL_SHININESS, 0.6*128.0);
	}

	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

		glFogi (GL_FOG_MODE, m_fogMode);
		glFogfv (GL_FOG_COLOR, fogColor);
		glFogf (GL_FOG_DENSITY, 0.35);
		glHint (GL_FOG_HINT, GL_DONT_CARE);
		glFogf (GL_FOG_START, 1.0);
		glFogf (GL_FOG_END, 5.0);
	}

	glClearColor(0.5, 0.5, 0.5, 1.0);  /* fog color */

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_FOG);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Lesson_6_5::renderSphere (GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef (x, y, z);
	OGLShapes::solidSphere(0.4, 16, 16);
	glPopMatrix();
}

void Lesson_6_5::draw()
{
	renderSphere (-2., -0.5, -1.0);
	renderSphere (-1., -0.5, -2.0);
	renderSphere (0., -0.5, -3.0);
	renderSphere (1., -0.5, -4.0);
	renderSphere (2., -0.5, -5.0);
}

bool Lesson_6_5::sendMessage(int message, int mode, int x, int y)
{
	switch (message)
	{
	case SDLK_f:
		if (m_fogMode == GL_EXP) {
			m_fogMode = GL_EXP2;
			printf ("Fog mode is GL_EXP2\n");
		}
		else if (m_fogMode == GL_EXP2) {
			m_fogMode = GL_LINEAR;
			printf ("Fog mode is GL_LINEAR\n");
		}
		else if (m_fogMode == GL_LINEAR) {
			m_fogMode = GL_EXP;
			printf ("Fog mode is GL_EXP\n");
		}
		glFogi (GL_FOG_MODE, m_fogMode);
		break;
	default:
		return false;
		break;
	}

	return true;
}
