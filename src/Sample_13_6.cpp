/*
 * Sample_13_6.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_13_6.h"
#include "OGLShapes.h"
#include "OGLInspector.h"

#include <SDL/SDL.h>

#define BUFSIZE 512

Sample_13_6::Sample_13_6()
{
}

Sample_13_6::~Sample_13_6()
{
}

void Sample_13_6::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 8.0, 0.0, 8.0, -0.5, 2.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_13_6::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawRects(GL_RENDER);
}

void Sample_13_6::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	glDepthRange(0.0, 1.0);  /* The default z mapping */
}

void Sample_13_6::restoreGL()
{
	glPopAttrib();
}

bool Sample_13_6::sendMessage(int message, int mode, int x, int y)
{
	GLuint selectBuf[BUFSIZE];
	GLint hits;
	GLint viewport[4];

	switch (message) {
	case SDL_BUTTON_LEFT:
		/*  sets up selection mode, name stack,
		 *  and projection matrix for picking.  Then the
		 *  objects are drawn.
		 */
		if (mode==SDL_PRESSED) {
			glGetIntegerv(GL_VIEWPORT, viewport);

			glSelectBuffer(BUFSIZE, selectBuf);
			(void) glRenderMode(GL_SELECT);

			glInitNames();
			glPushName(0);

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			/*  create 5x5 pixel picking region near cursor location */
			gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3] - y),
					5.0, 5.0, viewport);
			glOrtho(0.0, 8.0, 0.0, 8.0, -0.5, 2.5);
			drawRects(GL_SELECT);
			glPopMatrix();

			hits = glRenderMode(GL_RENDER);
			processHits(hits, selectBuf);
		}
		break;
	default:
		return false;
		break;
	}

	return true;
}

/* The three rectangles are drawn.  In selection mode,
 * each rectangle is given the same name.  Note that
 * each rectangle is drawn with a different z value.
 */
void Sample_13_6::drawRects(GLenum mode)
{
	if (mode == GL_SELECT)
		glLoadName(1);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3i(2, 0, 0);
	glVertex3i(2, 6, 0);
	glVertex3i(6, 6, 0);
	glVertex3i(6, 0, 0);
	glEnd();
	if (mode == GL_SELECT)
		glLoadName(2);
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3i(3, 2, -1);
	glVertex3i(3, 8, -1);
	glVertex3i(8, 8, -1);
	glVertex3i(8, 2, -1);
	glEnd();
	if (mode == GL_SELECT)
		glLoadName(3);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3i(0, 2, -2);
	glVertex3i(0, 7, -2);
	glVertex3i(5, 7, -2);
	glVertex3i(5, 2, -2);
	glEnd();
}

/*  processHits prints out the contents of the
 *  selection array.
 */
void Sample_13_6::processHits (GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint names, *ptr;

	printf("hits = %d\n", hits);
	ptr = (GLuint *) buffer;
	for (i = 0; i < hits; i++) {  /* for each hit  */
		names = *ptr;
		printf(" number of names for hit = %d\n", names); ptr++;
		printf("  z1 is %g;", (float) *ptr/0x7fffffff); ptr++;
		printf(" z2 is %g\n", (float) *ptr/0x7fffffff); ptr++;
		printf("   the name is ");
		for (j = 0; j < names; j++) {  /* for each name */
			printf("%d ", *ptr); ptr++;
		}
		printf("\n");
	}
}

