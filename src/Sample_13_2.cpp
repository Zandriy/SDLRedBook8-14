/*
 * Sample_13_2.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_13_2.h"
#include "OGLShapes.h"
#include "OGLInspector.h"

#include <SDL/SDL.h>

#define BUFSIZE 512

Sample_13_2::Sample_13_2()
{
}

Sample_13_2::~Sample_13_2()
{
}

void Sample_13_2::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	/* create a diamond shaped stencil area */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-3.0, 3.0, -3.0*(GLfloat)h/(GLfloat)w,
				3.0*(GLfloat)h/(GLfloat)w);
	else
		gluOrtho2D(-3.0*(GLfloat)w/(GLfloat)h,
				3.0*(GLfloat)w/(GLfloat)h, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_STENCIL_TEST);
	glClear(GL_STENCIL_BUFFER_BIT);
	glStencilFunc (GL_ALWAYS, 0x1, 0x1);
	glStencilOp (GL_REPLACE, GL_REPLACE, GL_REPLACE);
	glBegin(GL_QUADS);
	glVertex2f (-1.0, 0.0);
	glVertex2f (0.0, 1.0);
	glVertex2f (1.0, 0.0);
	glVertex2f (0.0, -1.0);
	glEnd();
	glDisable(GL_STENCIL_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 3.0, 7.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void Sample_13_2::draw()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawScene ();
	selectObjects ();
}

void Sample_13_2::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void Sample_13_2::restoreGL()
{
	glDisable(GL_DEPTH_TEST);

	glPopAttrib();
}


/* draw a triangle with vertices at (x1, y1), (x2, y2)
 * and (x3, y3) at z units away from the origin.
 */
void Sample_13_2::drawTriangle (GLfloat x1, GLfloat y1, GLfloat x2,
		GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z)
{
	glBegin (GL_TRIANGLES);
	glVertex3f (x1, y1, z);
	glVertex3f (x2, y2, z);
	glVertex3f (x3, y3, z);
	glEnd ();
}

/* draw a rectangular box with these outer x, y, and z values */
void Sample_13_2::drawViewVolume (GLfloat x1, GLfloat x2, GLfloat y1,
		GLfloat y2, GLfloat z1, GLfloat z2)
{
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_LINE_LOOP);
	glVertex3f (x1, y1, -z1);
	glVertex3f (x2, y1, -z1);
	glVertex3f (x2, y2, -z1);
	glVertex3f (x1, y2, -z1);
	glEnd ();

	glBegin (GL_LINE_LOOP);
	glVertex3f (x1, y1, -z2);
	glVertex3f (x2, y1, -z2);
	glVertex3f (x2, y2, -z2);
	glVertex3f (x1, y2, -z2);
	glEnd ();

	glBegin (GL_LINES);	/*  4 lines	*/
	glVertex3f (x1, y1, -z1);
	glVertex3f (x1, y1, -z2);
	glVertex3f (x1, y2, -z1);
	glVertex3f (x1, y2, -z2);
	glVertex3f (x2, y1, -z1);
	glVertex3f (x2, y1, -z2);
	glVertex3f (x2, y2, -z1);
	glVertex3f (x2, y2, -z2);
	glEnd ();
}

/* processHits prints out the contents of the selection array
 */
void Sample_13_2::processHits (GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint names, *ptr;

	printf ("hits = %d\n", hits);
	ptr = (GLuint *) buffer;
	for (i = 0; i < hits; i++) {	/*  for each hit  */
		names = *ptr;
		printf (" number of names for hit = %d\n", names); ptr++;
		printf("  z1 is %g;", (float) *ptr/0x7fffffff); ptr++;
		printf(" z2 is %g\n", (float) *ptr/0x7fffffff); ptr++;
		printf ("   the name is ");
		for (j = 0; j < names; j++) {	/*  for each name */
			printf ("%d ", *ptr); ptr++;
		}
		printf ("\n");
	}
}

/* drawScene draws 4 triangles and a wire frame
 * which represents the viewing volume.
 */
void Sample_13_2::drawScene()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (40.0, 4.0/3.0, 1.0, 100.0);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	gluLookAt (7.5, 7.5, 12.5, 2.5, 2.5, -5.0, 0.0, 1.0, 0.0);
	glColor3f (0.0, 1.0, 0.0);	/*  green triangle	*/
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -5.0);
	glColor3f (1.0, 0.0, 0.0);	/*  red triangle	*/
	drawTriangle (2.0, 7.0, 3.0, 7.0, 2.5, 8.0, -5.0);
	glColor3f (1.0, 1.0, 0.0);	/*  yellow triangles	*/
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -1.0);
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -9.0);
	drawViewVolume (0.0, 5.0, 0.0, 5.0, 0.0, 10.0);
}

/* selectObjects "draws" the triangles in selection mode,
 * assigning names for the triangles.  Note that the third
 * and fourth triangles share one name, so that if either
 * or both triangles intersects the viewing/clipping volume,
 * only one hit will be registered.
 */
void Sample_13_2::selectObjects()
{
	GLuint selectBuf[BUFSIZE];
	GLint hits;

	glSelectBuffer (BUFSIZE, selectBuf);
	(void) glRenderMode (GL_SELECT);

	glInitNames();
	glPushName(0);

	glPushMatrix ();
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0.0, 5.0, 0.0, 5.0, 0.0, 10.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glLoadName(1);
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -5.0);
	glLoadName(2);
	drawTriangle (2.0, 7.0, 3.0, 7.0, 2.5, 8.0, -5.0);
	glLoadName(3);
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -1.0);
	drawTriangle (2.0, 2.0, 3.0, 2.0, 2.5, 3.0, -9.0);
	glPopMatrix ();

	hits = glRenderMode (GL_RENDER);
	processHits (hits, selectBuf);
}
