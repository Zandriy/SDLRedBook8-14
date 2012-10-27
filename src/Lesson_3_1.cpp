/*
 * Lesson_3_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_1.h"

#include "OGLShapes.h"

Lesson_3_1::Lesson_3_1() {
	// TODO Auto-generated constructor stub
}

Lesson_3_1::~Lesson_3_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_1::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
}

void Lesson_3_1::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_3_1::draw()
{
	glColor3f (1.0, 1.0, 1.0);

	// Set camera
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glScalef(1.0, 2.0, 1.0);

	OGLShapes::wireCube(2.0);
}
