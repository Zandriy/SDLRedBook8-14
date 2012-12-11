/*
 * Sample_8_5.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_5.h"
#include <SDL/SDL.h>

Sample_8_5::Sample_8_5()
:	m_bImageCreated(false)
,	m_zoomFactor( 1.0 )
,	m_height(0)
,	m_bMotion(false)
,	m_X(0)
,	m_Y(0)
{
}

Sample_8_5::~Sample_8_5()
{
}

void Sample_8_5::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	m_height = (GLint) h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_5::draw()
{
	glRasterPos2i(0, 0);
	glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB,
			GL_UNSIGNED_BYTE, m_checkImage);

	if (m_bMotion)
		motion(m_X, m_Y);
}

void Sample_8_5::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.5, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeCheckImage();

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_5::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}


void Sample_8_5::makeCheckImage()
{
	if (m_bImageCreated)
		return; // the image has been already created

	int i, j, c;

	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			c = ((((i&0x8)==0)^((j&0x8))==0))*255;
			m_checkImage[i][j][0] = (GLubyte) c;
			m_checkImage[i][j][1] = (GLubyte) c;
			m_checkImage[i][j][2] = (GLubyte) c;
		}
	}

	m_bImageCreated = true;
}

void Sample_8_5::motion(int x, int y)
{
	static GLint screeny;

	screeny = m_height - (GLint) y;
	glRasterPos2i (x, screeny);
	glPixelZoom (m_zoomFactor, m_zoomFactor);
	glCopyPixels (0, 0, checkImageWidth, checkImageHeight, GL_COLOR);
	glPixelZoom (1.0, 1.0);
}

bool Sample_8_5::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_r:
		m_zoomFactor = 1.0;
		printf ("zoomFactor reset to 1.0\n");
		drawGLScene();
		break;
	case SDLK_z:
		if (KMOD_NONE != mode)
			m_zoomFactor += 0.5;
		else
			m_zoomFactor -= 0.5;

		if (m_zoomFactor >= 3.0)
			m_zoomFactor = 3.0;
		if (m_zoomFactor <= 0.5)
			m_zoomFactor = 0.5;

		printf ("zoomFactor is now %4.1f\n", m_zoomFactor);
		break;
	case SDL_MOUSEBUTTONDOWN:
		m_bMotion = true;
		m_X = x;
		m_Y = y;
		break;
	case SDL_MOUSEBUTTONUP:
		m_bMotion = false;
		break;
	case SDL_MOUSEMOTION:
		if (mode)
		{
			m_X = x;
			m_Y = y;
		}
		break;
	default:

		return false;
		break;
	}

	return true;
}
