/*
 * Lesson_8_1.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_8_1.h"

GLubyte rasters[24] = {
   0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
   0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
   0xff, 0xc0, 0xff, 0xc0};

Lesson_8_1::Lesson_8_1() {
	// TODO Auto-generated constructor stub

}

Lesson_8_1::~Lesson_8_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_8_1::reshape(int w, int h)
{
	   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   glOrtho (0, w, 0, h, -1.0, 1.0);
	   glMatrixMode(GL_MODELVIEW);
}

void Lesson_8_1::drawGLScene()
{
	   glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	   glClearColor (0.0, 0.0, 0.0, 0.0);

	   glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	   glClearColor (0.0, 0.0, 0.0, 0.0);

	draw();
}

void Lesson_8_1::draw()
{
	   glClear(GL_COLOR_BUFFER_BIT);
	   glColor3f (1.0, 1.0, 1.0);
	   glRasterPos2i (20, 20);
	   glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	   glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	   glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	   glFlush();
}
