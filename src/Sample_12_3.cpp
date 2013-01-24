/*
 * Sample_12_3.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_3.h"
#include "OGLShapes.h"

const GLfloat ctrlpoints_12_3[4][4][3] = {
		{{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0}
		, {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}}
		, {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0}
		, {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}}
		, {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0}
		, {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}}
		, {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0}
		, {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
};

Sample_12_3::Sample_12_3()
{
}

Sample_12_3::~Sample_12_3()
{
}

void Sample_12_3::reshape(int w, int h)
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

void Sample_12_3::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(85.0, 1.0, 1.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
}

void Sample_12_3::initlights()
{
	GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
	GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void Sample_12_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
			0, 1, 12, 4, &ctrlpoints_12_3[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_AUTO_NORMAL);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	initlights();       /* for lighted version only */
}

void Sample_12_3::restoreGL()
{
	glPopAttrib();
}
