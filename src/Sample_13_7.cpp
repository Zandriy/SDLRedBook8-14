/*
 * Sample_13_7.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_13_7.h"
#include "OGLShapes.h"
#include "OGLInspector.h"

#include <SDL/SDL.h>

#define BUFSIZE 1024

Sample_13_7::Sample_13_7()
{
}

Sample_13_7::~Sample_13_7()
{
}

void Sample_13_7::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0.0, 100.0, 0.0, 100.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_13_7::draw()
{
	GLfloat feedBuffer[BUFSIZE];
	GLint size;

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawGeometry (GL_RENDER);

	glFeedbackBuffer (BUFSIZE, GL_3D_COLOR, feedBuffer);
	(void) glRenderMode (GL_FEEDBACK);
	drawGeometry (GL_FEEDBACK);

	size = glRenderMode (GL_RENDER);
	printBuffer (size, feedBuffer);
}

void Sample_13_7::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Sample_13_7::restoreGL()
{
	glPopAttrib();
}

/* Draw a few lines and two points, one of which will
 * be clipped.  If in feedback mode, a passthrough token
 * is issued between the each primitive.
 */
void Sample_13_7::drawGeometry (GLenum mode)
{
	glBegin (GL_LINE_STRIP);
	glNormal3f (0.0, 0.0, 1.0);
	glVertex3f (30.0, 30.0, 0.0);
	glVertex3f (50.0, 60.0, 0.0);
	glVertex3f (70.0, 40.0, 0.0);
	glEnd ();
	if (mode == GL_FEEDBACK)
		glPassThrough (1.0);
	glBegin (GL_POINTS);
	glVertex3f (-100.0, -100.0, -100.0);  /*  will be clipped  */
	glEnd ();
	if (mode == GL_FEEDBACK)
		glPassThrough (2.0);
	glBegin (GL_POINTS);
	glNormal3f (0.0, 0.0, 1.0);
	glVertex3f (50.0, 50.0, 0.0);
	glEnd ();
}


/* Write contents of one vertex to stdout.	*/
void Sample_13_7::print3DcolorVertex (GLint size, GLint *count,
		GLfloat *buffer)
{
	int i;

	printf ("  ");
	for (i = 0; i < 7; i++) {
		printf ("%4.2f ", buffer[size-(*count)]);
		*count = *count - 1;
	}
	printf ("\n");
}

/*  Write contents of entire buffer.  (Parse tokens!)	*/
void Sample_13_7::printBuffer(GLint size, GLfloat *buffer)
{
	GLint count;
	GLfloat token;

	count = size;
	while (count) {
		token = buffer[size-count]; count--;
		if (token == GL_PASS_THROUGH_TOKEN) {
			printf ("GL_PASS_THROUGH_TOKEN\n");
			printf ("  %4.2f\n", buffer[size-count]);
			count--;
		}
		else if (token == GL_POINT_TOKEN) {
			printf ("GL_POINT_TOKEN\n");
			print3DcolorVertex (size, &count, buffer);
		}
		else if (token == GL_LINE_TOKEN) {
			printf ("GL_LINE_TOKEN\n");
			print3DcolorVertex (size, &count, buffer);
			print3DcolorVertex (size, &count, buffer);
		}
		else if (token == GL_LINE_RESET_TOKEN) {
			printf ("GL_LINE_RESET_TOKEN\n");
			print3DcolorVertex (size, &count, buffer);
			print3DcolorVertex (size, &count, buffer);
		}
	}
}

