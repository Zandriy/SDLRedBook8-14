/*
 * Lesson_3_5.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_5.h"

#include "OGLShapes.h"

Lesson_3_5::Lesson_3_5()
{
}

Lesson_3_5::~Lesson_3_5() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_5::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 20.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_3_5::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();
}

void Lesson_3_5::draw()
{
	GLdouble eqn0[4] = {0.0, 1.0, 0.0, 0.0};
	GLdouble eqn1[4] = {1.0, 0.0, 0.0, 0.0};

	glColor3f (1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);

	glClipPlane(GL_CLIP_PLANE0, eqn0);
	glEnable(GL_CLIP_PLANE0);

	glClipPlane(GL_CLIP_PLANE1, eqn1);
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90.0, 1.0, 0.0, 0.0);

	OGLShapes::wireSphere(2.0, 20, 16);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
}
