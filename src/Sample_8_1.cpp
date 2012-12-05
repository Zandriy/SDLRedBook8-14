/*
 * Sample_8_1.cpp
 *
 *  Created on: Dec 6, 2012
 *      Author: Andrew Zhabura
 */

#include "Sample_8_1.h"

GLubyte rasters[24] = {
		0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
		0xc0, 0x00, 0xff, 0x00, 0xff, 0x00, 0xc0, 0x00,
		0xc0, 0x00, 0xc0, 0x00, 0xff, 0xc0, 0xff, 0xc0
};

Sample_8_1::Sample_8_1()
{
}

Sample_8_1::~Sample_8_1()
{
}

void Sample_8_1::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void Sample_8_1::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glRasterPos2i (5, 5);
	glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
}

void Sample_8_1::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushClientAttrib(GL_CLIENT_PIXEL_STORE_BIT);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_1::restoreGL()
{
	glPopAttrib();
	glPopClientAttrib();
}
