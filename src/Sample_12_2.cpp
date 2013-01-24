/*
 * Sample_12_2.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_2.h"
#include "OGLShapes.h"

const GLfloat ctrlpoints_12_2[4][4][3] = {
		{{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0}
		, {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}}
		, {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0}
		, {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}}
		, {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0}
		, {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}}
		, {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0}
		, {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
};

Sample_12_2::Sample_12_2()
{
}

Sample_12_2::~Sample_12_2()
{
}

void Sample_12_2::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
				5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
				5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_12_2::draw()
{
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix ();
	glRotatef(85.0, 1.0, 1.0, 1.0);
	for (j = 0; j <= 8; j++) {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)i/30.0, (GLfloat)j/8.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)j/8.0, (GLfloat)i/30.0);
		glEnd();
	}
	glPopMatrix ();
}

void Sample_12_2::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
			0, 1, 12, 4, &ctrlpoints_12_2[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void Sample_12_2::restoreGL()
{
	glPopAttrib();
}
