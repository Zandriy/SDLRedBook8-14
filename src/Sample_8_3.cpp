/*
 * Sample_8_3.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_3.h"
#include <SDL/SDL.h>

#define		checkImageWidth		64
#define		checkImageHeight	64
#define		checkImageColors	3

Sample_8_3::Sample_8_3()
:	m_checkImage( NULL )
,	m_zoomFactor( 1.0 )
,	m_height(0)
{
}

Sample_8_3::~Sample_8_3()
{
}

void Sample_8_3::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	m_height = (GLint) h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_3::draw()
{
	glRasterPos2i(0, 0);
	glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB,
			GL_UNSIGNED_BYTE, m_checkImage);
}

void Sample_8_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeCheckImage();

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_3::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}


void Sample_8_3::makeCheckImage()
{
	if (m_checkImage)
		return;

	int i, j, c;

	m_checkImage = new GLubyte**[checkImageHeight];

	for (i = 0; i < checkImageHeight; ++i)
	{
		m_checkImage[i] = new GLubyte*[checkImageWidth];
		for (j = 0; j < checkImageWidth; ++j)
			m_checkImage[i][j] = new GLubyte[checkImageColors];
	}

	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			c = 200;//((((i&0x8)==0)^((j&0x8))==0))*255;
			m_checkImage[i][j][0] = (GLubyte) c;
			m_checkImage[i][j][1] = (GLubyte) c;
			m_checkImage[i][j][2] = (GLubyte) c;
		}
	}
}

void Sample_8_3::motion(int x, int y)
{
	static GLint screeny;

	screeny = m_height - (GLint) y;
	glRasterPos2i (x, screeny);
	glPixelZoom (m_zoomFactor, m_zoomFactor);
	glCopyPixels (0, 0, checkImageWidth, checkImageHeight, GL_COLOR);
	glPixelZoom (1.0, 1.0);
}

bool Sample_8_3::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_r:
		m_zoomFactor = 1.0;
		printf ("zoomFactor reset to 1.0\n");
		drawGLScene();
		break;
	case SDLK_z:
		if (KMOD_NONE == mode)
			m_zoomFactor += 0.5;
		else
			m_zoomFactor -= 0.5;

		if (m_zoomFactor >= 3.0)
			m_zoomFactor = 3.0;
		if (m_zoomFactor <= 0.5)
			m_zoomFactor = 0.5;

		printf ("zoomFactor is now %4.1f\n", m_zoomFactor);
		break;
	case SDL_BUTTON_LEFT:
	case SDL_BUTTON_RIGHT:

		if (mode==SDL_PRESSED)
		{
			initGL();
			motion(x, y);
			restoreGL();

			printf ("x = %d; y = %d\n", x, y);
		}
		else
			return false;

		break;
	default:
		return false;
		break;
	}

	return true;
}
