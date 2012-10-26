/*
 * Lesson_3_5.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_5.h"

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

	wireSphere(2.0, 20, 16);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
}

void Lesson_3_5::wireSphere(GLdouble radius,GLint slices, GLint stacks)
{
	/*
	radius
	    The radius of the sphere.
	slices
	    The number of subdivisions around the Z axis (similar to lines of longitude).
	stacks
	    The number of subdivisions along the Z axis (similar to lines of latitude).
	*/

	radius = radius > 0 ? radius : radius * -1;

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	GLdouble size = radius;

	GLfloat vertices[] = {
			-size, -size,  size,
			 size, -size,  size,
			 size,  size,  size,
			-size,  size,  size,
			-size, -size, -size,
			 size, -size, -size,
			 size,  size, -size,
			-size,  size, -size
	};

	GLubyte allIndices[] = {
			  4, 7, 6, 5
			, 1, 2, 6, 5
			, 0, 1, 5, 4
			, 0, 3, 2, 1
			, 0, 4, 7, 3
			, 2, 3, 7, 6
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);

	glDisableClientState(GL_VERTEX_ARRAY);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
