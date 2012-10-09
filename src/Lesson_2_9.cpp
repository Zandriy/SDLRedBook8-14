/*
 * Lesson_2_9.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_2_9.h"

Lesson_2_9::Lesson_2_9() {
	// TODO Auto-generated constructor stub

}

Lesson_2_9::~Lesson_2_9() {
	// TODO Auto-generated destructor stub
}

void Lesson_2_9::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluOrtho2D(0.0, ( GLdouble )width, 0.0, ( GLdouble )height);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_2_9::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_2_9::draw()
{
	GLint vertices[] = {25, 25,
			100, 325,
			175, 25,
			175, 325,
			250, 25,
			325, 325};
	GLfloat colors[] = {1.0, 0.2, 0.2,
			0.2, 0.2, 1.0,
			0.8, 1.0, 0.2,
			0.75, 0.75, 0.75,
			0.35, 0.35, 0.35,
			0.5, 0.5, 0.5};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(2, GL_INT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glDrawArrays( GL_POLYGON, 0, 6 /*num of vertices*/ ); //Draw the vertices

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
