/*
 * Sample_8_9.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_9.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_8_9::Sample_8_9()
:	m_bImagSprt(false)
,	m_bLoad(false)
,	m_sink(GL_FALSE)
,	m_prevSink(GL_TRUE)
{
	m_image.loadBMP( "textures/pagoda.bmp" );
}

Sample_8_9::~Sample_8_9()
{
}

void Sample_8_9::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) m_image.sizeX(), 0.0, (GLdouble) m_image.sizeY() );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_9::draw()
{
	GLubyte values[6];

	OGLError err;
	OGLInspector inspector;

	if (m_prevSink != m_sink)
	{
		m_bImagSprt = inspector.ImagingSupported();
		if (m_bImagSprt)
		{
			glMinmax(GL_MINMAX, GL_RGB, m_sink);

			if (err.checkError())
			{
				glEnable(GL_MINMAX);
				glResetMinmax(GL_MINMAX);
			}
			else
				m_bImagSprt = false;
		}
		else
		{
			m_prevSink = m_sink;
			printf ("GL_ARB_imaging is not supported\n");
			m_bImagSprt = false;
		}
	}

	glRasterPos2i(5, 5);
	glDrawPixels( m_image.sizeX(), m_image.sizeY(), GL_RGB,
			GL_UNSIGNED_BYTE, m_image.data() );

	if (m_prevSink != m_sink)
	{
		m_prevSink = m_sink;
		glGetMinmax(GL_MINMAX,GL_TRUE,GL_RGB,GL_UNSIGNED_BYTE,values);

		printf("====== MIN-MAX ======\n");
		printf("Red : min = %d max = %d\n",values[0],values[3]);
		printf("Green: min = %d max = %d\n",values[1],values[4]);
		printf("Blue : min = %d max = %d\n",values[3],values[5]);
	}
}

void Sample_8_9::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.5, 0.0, 0.6, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_9::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_8_9::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_s:
		m_sink = !m_sink;
		if (m_sink)
			printf("SINK\n");
		else
			printf("NO SINK\n");
		break;
	case SDLK_EQUALS:
		m_bLoad = true;
		break;
	case SDLK_1:
		if (!m_bLoad)
			return false;
		m_image.loadBMP( "textures/pagoda.bmp" );
		m_prevSink = !m_prevSink;
		break;
	case SDLK_2:
		if (!m_bLoad)
			return false;
		m_image.loadBMP( "textures/fish.bmp" );
		m_prevSink = !m_prevSink;
		break;
	case SDLK_3:
		if (!m_bLoad)
			return false;
		m_image.loadBMP( "textures/forest.bmp" );
		m_prevSink = !m_prevSink;
		break;
	default:
		m_bLoad = false;
		return false;
		break;
	}

	if (message != SDLK_EQUALS)
		m_bLoad = false;

	drawGLScene();
	return true;
}
