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
:	m_prevTblType(NONE)
,	m_tblType(INVERT)
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

	if (m_tblType != NONE)
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
	if (m_prevTblType == m_tblType)
		return; // the color table has been already created

	switch (m_tblType)
	{
	case INVERT:
		for (int i = 0; i < tableSize; ++i) {
			m_clrTable[i][0] = tableSize-(i+1);
			m_clrTable[i][1] = tableSize-(i+1);
			m_clrTable[i][2] = tableSize-(i+1);
		}
		break;
	case RED_CHANNEL:
		for (int i = 0; i < tableSize; ++i) {
			m_clrTable[i][0] = i;
			m_clrTable[i][1] = 0.0;
			m_clrTable[i][2] = 0.0;
		}
		break;
	case GREEN_CHANNEL:
		for (int i = 0; i < tableSize; ++i) {
			m_clrTable[i][0] = 0.0;
			m_clrTable[i][1] = i;
			m_clrTable[i][2] = 0.0;
		}
		break;
	case BLUE_CHANNEL:
		for (int i = 0; i < tableSize; ++i) {
			m_clrTable[i][0] = 0.0;
			m_clrTable[i][1] = 0.0;
			m_clrTable[i][2] = i;
		}
		break;
	default:
		m_tblType = NONE;
		break;
	}

	m_prevTblType = m_tblType;
}

bool Sample_8_5::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_o:
		m_tblType = NONE;
		printf ("Original picture\n");
		break;
	case SDLK_i:
		m_tblType = INVERT;
		printf ("Inverted picture\n");
		break;
	case SDLK_r:
		m_tblType = RED_CHANNEL;
		printf ("Red channel of picture\n");
		break;
	case SDLK_g:
		m_tblType = GREEN_CHANNEL;
		printf ("Green channel of picture\n");
		break;
	case SDLK_b:
		m_tblType = BLUE_CHANNEL;
		printf ("Blue channel of picture\n");
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}
