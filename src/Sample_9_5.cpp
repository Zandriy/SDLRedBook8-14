/*
 * Sample_9_5.cpp
 *
 *  Created on: Dec 26, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_9_5.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_9_5::Sample_9_5()
:	m_texName(0)
,	m_imageCreated(false)
{
}

Sample_9_5::~Sample_9_5()
{
}

void Sample_9_5::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 30000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -3.6);
}

void Sample_9_5::draw()
{
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
	glTexCoord2f(0.0, 8.0); glVertex3f(-2.0, 1.0, 0.0);
	glTexCoord2f(8.0, 8.0); glVertex3f(2000.0, 1.0, -6000.0);
	glTexCoord2f(8.0, 0.0); glVertex3f(2000.0, -1.0, -6000.0);
	glEnd();
}

void Sample_9_5::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeImages();

	glBindTexture(GL_TEXTURE_2D, m_texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_NEAREST_MIPMAP_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage32);
	glTexImage2D(GL_TEXTURE_2D, 1, GL_RGBA, 16, 16, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage16);
	glTexImage2D(GL_TEXTURE_2D, 2, GL_RGBA, 8, 8, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage8);
	glTexImage2D(GL_TEXTURE_2D, 3, GL_RGBA, 4, 4, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage4);
	glTexImage2D(GL_TEXTURE_2D, 4, GL_RGBA, 2, 2, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage2);
	glTexImage2D(GL_TEXTURE_2D, 5, GL_RGBA, 1, 1, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, mipmapImage1);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glEnable(GL_TEXTURE_2D);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Sample_9_5::restoreGL()
{
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopClientAttrib();
}

void Sample_9_5::makeImages()
{
	if (m_imageCreated)
		return;

	glGenTextures(1, &m_texName);

	int i, j;

	for (i = 0; i < SZ_LVL0; i++) {
		for (j = 0; j < SZ_LVL0; j++) {
			mipmapImage32[i][j][0] = 255;
			mipmapImage32[i][j][1] = 255;
			mipmapImage32[i][j][2] = 0;
			mipmapImage32[i][j][3] = 255;
		}
	}
	for (i = 0; i < SZ_LVL1; i++) {
		for (j = 0; j < SZ_LVL1; j++) {
			mipmapImage16[i][j][0] = 255;
			mipmapImage16[i][j][1] = 0;
			mipmapImage16[i][j][2] = 255;
			mipmapImage16[i][j][3] = 255;
		}
	}
	for (i = 0; i < SZ_LVL2; i++) {
		for (j = 0; j < SZ_LVL2; j++) {
			mipmapImage8[i][j][0] = 255;
			mipmapImage8[i][j][1] = 0;
			mipmapImage8[i][j][2] = 0;
			mipmapImage8[i][j][3] = 255;
		}
	}
	for (i = 0; i < SZ_LVL3; i++) {
		for (j = 0; j < SZ_LVL3; j++) {
			mipmapImage4[i][j][0] = 0;
			mipmapImage4[i][j][1] = 255;
			mipmapImage4[i][j][2] = 0;
			mipmapImage4[i][j][3] = 255;
		}
	}
	for (i = 0; i < SZ_LVL4; i++) {
		for (j = 0; j < SZ_LVL4; j++) {
			mipmapImage2[i][j][0] = 0;
			mipmapImage2[i][j][1] = 0;
			mipmapImage2[i][j][2] = 255;
			mipmapImage2[i][j][3] = 255;
		}
	}
	mipmapImage1[0][0][0] = 255;
	mipmapImage1[0][0][1] = 255;
	mipmapImage1[0][0][2] = 255;
	mipmapImage1[0][0][3] = 255;

	m_imageCreated = true;
}
