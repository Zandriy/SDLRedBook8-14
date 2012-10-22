/*
 * Lesson_3_2.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_2.h"

Lesson_3_2::Lesson_3_2() {
	// TODO Auto-generated constructor stub
}

Lesson_3_2::~Lesson_3_2() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_2::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	glOrtho(-3.0, 3.0, -1.0, 1.0, -1.0, 1.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
}

void Lesson_3_2::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();
}

void Lesson_3_2::draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	draw_triangle();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0xF0F0);
	glLoadIdentity();
	glTranslatef(-2.0,0.0,0.0);
	draw_triangle();

	glLineStipple(1,0xF00F);
	glLoadIdentity();
	glScalef(1.5,0.5,1.0);
	draw_triangle();

	glLineStipple(1,0x8888);
	glLoadIdentity();
	glRotatef(90.0,0.0,0.0,1.0);
	draw_triangle();
	glDisable(GL_LINE_STIPPLE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void Lesson_3_2::draw_triangle()
{
	GLdouble r = 0.95;
	GLdouble x = r * 0.866025;	// r * cos(30)
	GLdouble y = r * 0.5;		// r * sin(30)

	glBegin(GL_TRIANGLES);
	glVertex3f( -x, -y, 0.0);
	glVertex3f(  x, -y, 0.0);
	glVertex3f(0.0,  r, 0.0);
	glEnd();
}
