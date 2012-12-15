/*
 * Sample_8_7.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_7.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"

GLfloat m[16] = {
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 1.0,
};

Sample_8_7::Sample_8_7()
:	m_reversing(false)
,	m_prevReversing(true)
{
	m_image.loadBMP( "textures/tree_mount.bmp" );
}

Sample_8_7::~Sample_8_7()
{
}

void Sample_8_7::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) m_image.sizeX(), 0.0, (GLdouble) m_image.sizeY() );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_7::draw()
{
	OGLError err;

	if (m_prevReversing != m_reversing)
	{
		setColorMatrix();

		err.checkError();

		m_prevReversing = m_reversing;
	}

	glRasterPos2i(5, 5);
	glDrawPixels( m_image.sizeX(), m_image.sizeY(), GL_RGB,
			GL_UNSIGNED_BYTE, m_image.data() );

	glDisable(GL_CONVOLUTION_2D);

}

void Sample_8_7::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.9, 0.0, 0.6, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_7::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_8_7::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_r:
		m_reversing = !m_reversing;
		if (m_reversing)
			printf ("Reverted picture\n");
		else
			printf ("Original picture\n");
		break;
	case SDLK_1:
		m_image.loadBMP( "textures/tree_mount.bmp" );
		break;
	case SDLK_2:
		m_image.loadBMP( "textures/iceberg.bmp" );
		break;
	case SDLK_3:
		m_image.loadBMP( "textures/forest.bmp" );
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_8_7::setColorMatrix()
{
	glMatrixMode(GL_COLOR);

	if (m_reversing)
		glLoadMatrixf(m);
	else
		glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
}
