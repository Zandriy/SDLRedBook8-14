/*
 * Lesson_2_13.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_2_13.h"

#define X .525731112119133606
#define Z .850650808352039932

#define VERTICES_QTY	12
#define TRIANGLES_ORDER	20
#define QTY				3

GLfloat vdata[VERTICES_QTY][QTY] = {
		{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, Z}, {X, 0.0, -Z},
		{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
		{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};

GLuint tindices[TRIANGLES_ORDER][QTY] = {
		{1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
		{1,10,8},{10,3,8},{8,3,5},{3,2,5},{3,7,2},
		{3,10,7},{10,6,7},{6,11,7},{6,0,11},{6,1,0},
		{10,1,6},{11,0,9},{2,11,9},{5,2,9},{11,2,7}
};

Lesson_2_13::Lesson_2_13()
{
}

Lesson_2_13::~Lesson_2_13() {
	// TODO Auto-generated destructor stub
}

void Lesson_2_13::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_2_13::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_2_13::draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < TRIANGLES_ORDER; ++i )
	{
		glColor3f (0.5 / (i%QTY + 1), 0.1 * (i%QTY), 0.9 / (i%QTY + 1));

		glVertex3fv(&vdata[ tindices[i][0] ] [0]);
		glVertex3fv(&vdata[ tindices[i][1] ] [0]);
		glVertex3fv(&vdata[ tindices[i][2] ] [0]);
	}
	glEnd();
}

