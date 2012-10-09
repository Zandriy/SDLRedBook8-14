/*
 * Lesson_2_5.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

#include "Lesson_2_5.h"

Lesson_2_5::Lesson_2_5() {
	// TODO Auto-generated constructor stub

}

Lesson_2_5::~Lesson_2_5() {
	// TODO Auto-generated destructor stub
}

void Lesson_2_5::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluOrtho2D(0.0, 400.0, 0.0, 150.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_2_5::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_2_5::draw()
{
	   int i;

	   glClear (GL_COLOR_BUFFER_BIT);

	/* select white for all lines  */
	   glColor3f (1.0, 1.0, 1.0);

	/* in 1st row, 3 lines, each with a different stipple  */
	   glEnable (GL_LINE_STIPPLE);

	   glLineStipple (1, 0x0101);  /*  dotted  */
	   drawOneLine (50.0, 125.0, 150.0, 125.0);
	   glLineStipple (1, 0x00FF);  /*  dashed  */
	   drawOneLine (150.0, 125.0, 250.0, 125.0);
	   glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
	   drawOneLine (250.0, 125.0, 350.0, 125.0);

	/* in 2nd row, 3 wide lines, each with different stipple */
	   glLineWidth (5.0);
	   glLineStipple (1, 0x0101);  /*  dotted  */
	   drawOneLine (50.0, 100.0, 150.0, 100.0);
	   glLineStipple (1, 0x00FF);  /*  dashed  */
	   drawOneLine (150.0, 100.0, 250.0, 100.0);
	   glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
	   drawOneLine (250.0, 100.0, 350.0, 100.0);
	   glLineWidth (1.0);

	/* in 3rd row, 6 lines, with dash/dot/dash stipple  */
	/* as part of a single connected line strip         */
	   glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
	   glBegin (GL_LINE_STRIP);
	   for (i = 0; i < 7; i++)
	      glVertex2f (50.0 + ((GLfloat) i * 50.0), 75.0);
	   glEnd ();

	/* in 4th row, 6 independent lines with same stipple  */
	   for (i = 0; i < 6; i++) {
	      drawOneLine (50.0 + ((GLfloat) i * 50.0), 50.0,
	         50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
	   }

	/* in 5th row, 1 line, with dash/dot/dash stipple    */
	/* and a stipple repeat factor of 5                  */
	   glLineStipple (5, 0x1C47);  /*  dash/dot/dash  */
	   drawOneLine (50.0, 25.0, 350.0, 25.0);

	   glDisable (GL_LINE_STIPPLE);
}
