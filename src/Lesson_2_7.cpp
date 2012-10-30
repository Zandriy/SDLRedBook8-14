/*
 * Lesson_2_7.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_2_7.h"

#define SIZE 2
#define X	0
#define Y	1

#define	 X_SIZE	100.0
#define	 Y_SIZE	100.0

#define X0	10.0
#define Y0	10.0
#define X1	90.0
#define Y1	10.0
#define X2	60.0
#define Y2	90.0

Lesson_2_7::Lesson_2_7()
:	V0(new GLfloat[SIZE])
,	V1(new GLfloat[SIZE])
,	V2(new GLfloat[SIZE])
{
	V0[X] = X0;
	V0[Y] = Y0;
	V1[X] = X1;
	V1[Y] = Y1;
	V2[X] = X2;
	V2[Y] = Y2;
}

Lesson_2_7::~Lesson_2_7()
{
	// TODO Auto-generated destructor stub
}

void Lesson_2_7::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluOrtho2D(0.0, ( GLdouble )X_SIZE, 0.0, ( GLdouble )Y_SIZE);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
}

void Lesson_2_7::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	draw();
}

void Lesson_2_7::draw()
{
	glColor3f (0.0, 1.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glEdgeFlag(GL_TRUE);
	glVertex2fv(V0);
	glEdgeFlag(GL_FALSE);
	glVertex2fv(V1);
	glEdgeFlag(GL_TRUE);
	glVertex2fv(V2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
