/*
 * Sample_8_6.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_6.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"

GLfloat horizontal[3][3]={{0,-1,0},{0,1,0},{0,0,0}};
GLfloat vertical[3][3]= {{0,0,0},{-1,1,0},{0,0,0}};
GLfloat laplacian[3][3]= {{-0.125,-0.125,-0.125},
		{-0.125,1,-0.125},
		{-0.125,-0.125,-0.125}};


Sample_8_6::Sample_8_6()
:	m_fltrType(NONE)
{
	m_image.loadBMP( "textures/pyramid.bmp" );
}

Sample_8_6::~Sample_8_6()
{
}

void Sample_8_6::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) m_image.sizeX(), 0.0, (GLdouble) m_image.sizeY() );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_6::draw()
{
	OGLError err;

	if (m_fltrType != NONE)
	{
		setFilter();

		if (err.checkError())
			glEnable(GL_CONVOLUTION_2D);
		else
			m_fltrType = NONE;
	}

	glRasterPos2i(5, 5);
	glDrawPixels( m_image.sizeX(), m_image.sizeY(), GL_RGB,
			GL_UNSIGNED_BYTE, m_image.data() );

	glDisable(GL_CONVOLUTION_2D);

}

void Sample_8_6::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.5, 0.7, 0.0, 0.0);
	glShadeModel (GL_FLAT);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_6::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_8_6::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_o:
		m_fltrType = NONE;
		printf ("Original picture\n");
		break;
	case SDLK_h:
		m_fltrType = HORISONTAL;
		printf ("Inverted picture\n");
		break;
	case SDLK_v:
		m_fltrType = VERTICAL;
		printf ("Red channel of picture\n");
		break;
	case SDLK_l:
		m_fltrType = LAPLACIAN;
		printf ("Green channel of picture\n");
		break;
	case SDLK_1:
		m_image.loadBMP( "textures/pyramid.bmp" );
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

void Sample_8_6::setFilter()
{
	switch (m_fltrType)
	{
	case HORISONTAL:
		glConvolutionFilter2D(GL_CONVOLUTION_2D,GL_LUMINANCE,3,3,
				GL_LUMINANCE,GL_FLOAT,horizontal);
		break;
	case VERTICAL:
		glConvolutionFilter2D(GL_CONVOLUTION_2D,GL_LUMINANCE,3,3,
				GL_LUMINANCE,GL_FLOAT,vertical);
		break;
	case LAPLACIAN:
		glConvolutionFilter2D(GL_CONVOLUTION_2D,GL_LUMINANCE,3,3,
				GL_LUMINANCE,GL_FLOAT,laplacian);
		break;
	default:
		m_fltrType = NONE;
		break;
	}

}
