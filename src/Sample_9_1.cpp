/*
 * Sample_9_1.cpp
 *
 *  Created on: Dec 23, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_9_1.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_9_1::Sample_9_1()
:	m_texName(0)
,	m_imageCreated(false)
,	m_texDir(0)
,	m_texClamp(false)
,	m_texCoord(1.0)
{
}

Sample_9_1::~Sample_9_1()
{
}

void Sample_9_1::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -4.0);
}

void Sample_9_1::draw()
{
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
	glTexCoord2f(0.0, m_texCoord); glVertex3f(-2.0, 1.0, 0.0);
	glTexCoord2f(m_texCoord, m_texCoord); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(m_texCoord, 0.0); glVertex3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, m_texCoord); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(m_texCoord, m_texCoord); glVertex3f(2.41421, 1.0, -1.41421);
	glTexCoord2f(m_texCoord, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
	glEnd();
}

void Sample_9_1::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeCheckImage();

	glBindTexture(GL_TEXTURE_2D, m_texName);

	if(!m_texClamp)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		if (m_texDir == 1)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		else if (m_texDir == 2)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		}
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
			0, GL_RGBA, GL_UNSIGNED_BYTE, m_checkImage);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void Sample_9_1::restoreGL()
{
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_9_1::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_d:
		m_texDir++;
		if(m_texDir >= 3)
			m_texDir = 0;

		if (m_texDir == 1)
			printf("Clamp direction is WRAP_S\n");
		else if (m_texDir == 2)
			printf("Clamp direction is WRAP_T\n");
		else
			printf("Clamp direction is WRAP_S and WRAP_T\n");
		break;
	case SDLK_c:
		m_texClamp = !m_texClamp;
		if ( m_texClamp )
			printf("GL_CLAMP is set\n");
		else
			printf("GL_REPEAT is set\n");
		break;
	case SDLK_s:
		m_texCoord = m_texCoord < 3.0 ? 3.0 : 1.0;
		printf("Texture coordinate is %.1f\n", m_texCoord);
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_9_1::makeCheckImage()
{
	if (m_imageCreated)
		return;

	glGenTextures(1, &m_texName);

	int i, j, c;

	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			c = ((((i&0x8)==0)^((j&0x8))==0))*255;
			m_checkImage[i][j][0] = (GLubyte) c;
			m_checkImage[i][j][1] = (GLubyte) c;
			m_checkImage[i][j][2] = (GLubyte) c;
			m_checkImage[i][j][3] = (GLubyte) 255;
		}
	}

	m_imageCreated = true;
}
