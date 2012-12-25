/*
 * Sample_9_4.cpp
 *
 *  Created on: Dec 24, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_9_4.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_9_4::Sample_9_4()
:	m_texName(0)
,	m_imageCreated(false)
{
}

Sample_9_4::~Sample_9_4()
{
}

void Sample_9_4::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -3.6);
}

void Sample_9_4::draw()
{
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-2.25, -1.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-2.25, 1.0, 0.0);
	glTexCoord3f(1.0, 1.0, 1.0); glVertex3f(-0.25, 1.0, 0.0);
	glTexCoord3f(1.0, 0.0, 1.0); glVertex3f(-0.25, -1.0, 0.0);

	glTexCoord3f(0.0, 0.0, 1.0); glVertex3f(0.25, -1.0, 0.0);
	glTexCoord3f(0.0, 1.0, 1.0); glVertex3f(0.25, 1.0, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(2.25, 1.0, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(2.25, -1.0, 0.0);
	glEnd();
}

void Sample_9_4::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	makeImage();

	glBindTexture(GL_TEXTURE_3D,m_texName);

	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage3D(GL_TEXTURE_3D,0,GL_RGB,iwidth,iheight,idepth, 0,
			GL_RGB,GL_UNSIGNED_BYTE,m_image);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_3D);
}

void Sample_9_4::restoreGL()
{
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopClientAttrib();
}

void Sample_9_4::makeImage()
{
	if (m_imageCreated)
		return;

	glGenTextures(1, &m_texName);

	int s, t, r;

	for(s=0;s<16;s++)
		for(t=0;t<16;t++)
			for(r=0;r<16;r++)
			{
				m_image[r][t][s][0]=s*17;
				m_image[r][t][s][1]=t*17;
				m_image[r][t][s][2]=r*17;
			}

	m_imageCreated = true;
}
