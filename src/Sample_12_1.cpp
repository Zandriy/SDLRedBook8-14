/*
 * Sample_12_1.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_1.h"
#include "OGLShapes.h"

Sample_12_1::Sample_12_1()
{
}

Sample_12_1::~Sample_12_1()
{
}

void Sample_12_1::reshape(int w, int h)
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

void Sample_12_1::draw()
{
	int i;
	const int p = 30;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= p; i++)
		glEvalCoord1f((GLfloat) i/float(p) );
	glEnd();
	/* The following code displays the control points as dots. */
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
}

void Sample_12_1::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}

void Sample_12_1::restoreGL()
{
	glPopAttrib();
}
