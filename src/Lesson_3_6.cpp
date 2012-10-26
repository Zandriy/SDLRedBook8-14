/*
 * Lesson_3_6.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_6.h"
#include <SDL/SDL.h>

Lesson_3_6::Lesson_3_6()
:	m_year(0)
,	m_day(0)
{
}

Lesson_3_6::~Lesson_3_6() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_6::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 20.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void Lesson_3_6::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();
}

void Lesson_3_6::draw()
{
	glColor3f (1.0, 1.0, 1.0);
	glPushMatrix();

	// draw the Sun
	wireSphere(1.0, 20, 16);
	glRotatef((GLfloat)m_year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)m_day, 0.0, 1.0, 0.0);

	// draw a planet
	wireSphere(0.2, 10, 8);
	glPopMatrix();
}

bool Lesson_3_6::sendMessage(unsigned int  message, unsigned int mode)
{
	switch (message) {
	case SDLK_d:
		if (KMOD_NONE == mode)
			m_day = (m_day + 10) % 360;
		else
			m_day = (m_day - 10) % 360;
		drawGLScene();
		break;
		case SDLK_y:
			if (KMOD_NONE == mode)
				m_year = (m_year + 5) % 360;
			else
				m_year = (m_year - 5) % 360;
			drawGLScene();
		break;
		default:
			return false;
		break;
	}

	return true;
}

void Lesson_3_6::wireSphere(GLdouble radius,GLint slices, GLint stacks)
{
	/*
	radius
	    The radius of the sphere.
	slices
	    The number of subdivisions around the Z axis (similar to lines of longitude).
	stacks
	    The number of subdivisions along the Z axis (similar to lines of latitude).
	*/

	radius = radius > 0 ? radius : radius * -1;

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	GLdouble size = radius;

	GLfloat vertices[] = {
			-size, -size,  size,
			 size, -size,  size,
			 size,  size,  size,
			-size,  size,  size,
			-size, -size, -size,
			 size, -size, -size,
			 size,  size, -size,
			-size,  size, -size
	};

	GLubyte allIndices[] = {
			  4, 7, 6, 5
			, 1, 2, 6, 5
			, 0, 1, 5, 4
			, 0, 3, 2, 1
			, 0, 4, 7, 3
			, 2, 3, 7, 6
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);

	glDisableClientState(GL_VERTEX_ARRAY);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
