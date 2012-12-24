/*
 * Sample_9_3.cpp
 *
 *  Created on: Dec 24, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_9_3.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_9_3::Sample_9_3()
:	m_texName(0)
,	m_imageCreated(false)
,	m_drawSub(false)
{
}

Sample_9_3::~Sample_9_3()
{
}

void Sample_9_3::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -3.6);
}

void Sample_9_3::draw()
{
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
	glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
	glEnd();
}

void Sample_9_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeCheckImage();

	glBindTexture(GL_TEXTURE_2D, m_texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
			0, GL_RGBA, GL_UNSIGNED_BYTE, m_checkImage);
	if (m_drawSub)
		glTexSubImage2D(GL_TEXTURE_2D,0,12,44,subImageWidth,subImageHeight,
				GL_RGBA,GL_UNSIGNED_BYTE,m_subImage);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, m_texName);
}

void Sample_9_3::restoreGL()
{
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopClientAttrib();
}

bool Sample_9_3::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_s:
		m_drawSub = true;
		printf("Subtexture is drawn\n");
		break;
	case SDLK_r:
		m_drawSub = false;
		printf("Main texture is updated\n");
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_9_3::makeCheckImage()
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

	for (i=0;i<subImageHeight;i++)
	{
		for (j=0;j<subImageWidth;j++)
		{
			c=(((i&0x4)==0)^((j&0x4)==0))*255;
			m_subImage[i][j][0]=(GLubyte)c;
			m_subImage[i][j][1]=(GLubyte)0;
			m_subImage[i][j][2]=(GLubyte)0;
			m_subImage[i][j][3]=(GLubyte)255;
		}
	}

	m_imageCreated = true;
}
