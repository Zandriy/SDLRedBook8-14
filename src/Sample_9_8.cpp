/*
 * Sample_9_8.cpp
 *
 *  Created on: Jan 3, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_9_8.h"

#include <SDL/SDL.h>

#include "OGLError.h"
#include "OGLInspector.h"
#include "OGLShapes.h"

/*  planes for texture coordinate generation  */
static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};

Sample_9_8::Sample_9_8()
:	m_texName(0)
,	m_imageCreated(false)
,	m_currentGenMode(GL_OBJECT_LINEAR)
,	m_currentPlane(GL_OBJECT_PLANE)
{
	m_currentCoeff = xequalzero;
}

Sample_9_8::~Sample_9_8()
{
}

void Sample_9_8::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho (-3.5, 3.5, -3.5*(GLfloat)h/(GLfloat)w,
				3.5*(GLfloat)h/(GLfloat)w, -3.5, 3.5);
	else
		glOrtho (-3.5*(GLfloat)w/(GLfloat)h,
				3.5*(GLfloat)w/(GLfloat)h, -3.5, 3.5, -3.5, 3.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_9_8::draw()
{
	glPushMatrix ();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_1D, m_texName);
	OGLShapes::solidTorus(1.0, 2.0, 16, 16);
	glDisable(GL_LIGHTING);
	OGLShapes::solidCube(1.0);
	glPopMatrix ();
}

void Sample_9_8::initGL()
{
	GLfloat light_position1[] = { 0.0, 0.0, -1.0, 0.0 };

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_1D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);


	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glMaterialf (GL_FRONT, GL_SHININESS, 64.0);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeStripeImage();

	glBindTexture(GL_TEXTURE_1D, m_texName);

	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, m_stripeImage);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, m_currentGenMode);
	glTexGenfv(GL_S, m_currentPlane, m_currentCoeff);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Sample_9_8::restoreGL()
{
	glBindTexture(GL_TEXTURE_1D, NULL);
	glDisable(GL_TEXTURE_1D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_1D);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_AUTO_NORMAL);
	glDisable(GL_NORMALIZE);

	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_9_8::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_e:
		m_currentGenMode = GL_EYE_LINEAR;
		m_currentPlane = GL_EYE_PLANE;
		break;
	case SDLK_o:
		m_currentGenMode = GL_OBJECT_LINEAR;
		m_currentPlane = GL_OBJECT_PLANE;
		break;
	case SDLK_s:
		m_currentCoeff = slanted;
		break;
	case SDLK_x:
		m_currentCoeff = xequalzero;
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_9_8::makeStripeImage()
{
	if (m_imageCreated)
		return;

	glGenTextures(1, &m_texName);

	int j;

	for (j = 0; j < stripeImageWidth; j++) {
		m_stripeImage[4*j] = (GLubyte) ((j<=4) ? 255 : 0);
		m_stripeImage[4*j+1] = (GLubyte) ((j>4) ? 255 : 0);
		m_stripeImage[4*j+2] = (GLubyte) 0;
		m_stripeImage[4*j+3] = (GLubyte) 255;
	}

	m_imageCreated = true;
}
