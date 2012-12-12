/*
 * Sample_8_5.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_5.h"

#include <SDL/SDL.h>

#include "glext.h"

Sample_8_5::Sample_8_5()
:	m_bClrTableCreated(false)
,	m_bInvert(true)
{
	m_image.loadBMP( "textures/iceberg.bmp" );
}

Sample_8_5::~Sample_8_5()
{
}

void Sample_8_5::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) m_image.sizeX(), 0.0, (GLdouble) m_image.sizeY() );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_5::draw()
{
	createClrTable();

	if (m_bInvert)
	{
		glColorTable(GL_COLOR_TABLE, GL_RGB, tableSize,
				GL_RGB, GL_UNSIGNED_BYTE, (void*) m_clrTable);

		if (glGetError() == GL_INVALID_OPERATION)
			printf ("glColorTable() is not supported\n");
		else
			glEnable(GL_COLOR_TABLE);
	}

	glRasterPos2i(5, 5);
	glDrawPixels( m_image.sizeX(), m_image.sizeY(), GL_RGB,
			GL_UNSIGNED_BYTE, m_image.data() );

	glDisable(GL_COLOR_TABLE);

}

void Sample_8_5::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.5, 0.0, 0.7, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_5::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}


void Sample_8_5::createClrTable()
{
	if (m_bClrTableCreated)
		return; // the color table has been already created

	for (int i = 0; i < tableSize; ++i) {
		m_clrTable[i][0] = tableSize-(i+1);
		m_clrTable[i][1] = tableSize-(i+1);
		m_clrTable[i][2] = tableSize-(i+1);
	}

	m_bClrTableCreated = true;
}

bool Sample_8_5::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_i:
		m_bInvert = !m_bInvert;
		if (m_bInvert)
			printf ("Inverted picture\n");
		else
			printf ("Original picture\n");
		drawGLScene();
		break;
	default:

		return false;
		break;
	}

	return true;
}
