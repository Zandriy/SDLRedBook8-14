/*
 * Sample_8_8.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_8.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_8_8::Sample_8_8()
:	m_bImagSprt(false)
,	m_bLoad(false)
,	m_sink(GL_FALSE)
,	m_prevSink(GL_TRUE)
{
	m_image.loadBMP( "textures/mounts.bmp" );
}

Sample_8_8::~Sample_8_8()
{
}

void Sample_8_8::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) m_image.sizeX(), 0.0, (GLdouble) m_image.sizeY() );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_8::draw()
{
	int i;
	GLushort values[HISTOGRAM_SIZE][3];

	OGLError err;
	OGLInspector inspector;

	if (m_prevSink != m_sink)
	{
		m_prevSink = m_sink;

		m_bImagSprt = inspector.ImagingSupported();
		if (m_bImagSprt)
		{
			glHistogram(GL_HISTOGRAM, HISTOGRAM_SIZE, GL_RGB, m_sink);

			if (err.checkError())
				glEnable(GL_HISTOGRAM);
			else
				m_bImagSprt = false;
		}
		else
		{
			printf ("GL_ARB_imaging is not supported\n");
		}
	}

	glRasterPos2i(5, 5);
	glDrawPixels( m_image.sizeX(), m_image.sizeY(), GL_RGB,
			GL_UNSIGNED_BYTE, m_image.data() );

	if (m_bImagSprt)
	{
		if (m_sink)
			glGetHistogram(GL_HISTOGRAM, GL_FALSE, GL_RGB, GL_UNSIGNED_SHORT, values);
		else
			glGetHistogram(GL_HISTOGRAM, GL_TRUE, GL_RGB, GL_UNSIGNED_SHORT, values);

		/* Plot histogram */

		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		for ( i = 0; i < HISTOGRAM_SIZE; i++ )
			glVertex2s(i, values[i][0]);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 1.0, 0.0);
		for ( i = 0; i < HISTOGRAM_SIZE; i++ )
			glVertex2s(i, values[i][1]);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 1.0);
		for ( i = 0; i < HISTOGRAM_SIZE; i++ )
			glVertex2s(i, values[i][2]);
		glEnd();
	}

}

void Sample_8_8::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.5, 0.8, 0.6, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_8::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_8_8::sendMessage(int message, int mode, int x, int y)
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
		m_image.loadBMP( "textures/mounts.bmp" );
		m_prevSink = !m_prevSink;
		break;
	case SDLK_2:
		if (!m_bLoad)
			return false;
		m_image.loadBMP( "textures/iceberg.bmp" );
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
