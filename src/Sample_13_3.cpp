/*
 * Sample_13_3.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_13_3.h"
#include "OGLShapes.h"
#include "OGLInspector.h"

#include <SDL/SDL.h>

#define BUFSIZE 512

Sample_13_3::Sample_13_3()
{
	/*  Clear color value for every square on the board   */
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j ++)
			m_board[i][j] = 0;
}

Sample_13_3::~Sample_13_3()
{
}

void Sample_13_3::reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0, 3.0, 0.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_13_3::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawSquares (GL_RENDER);

}

void Sample_13_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glClearColor (0.0, 0.0, 0.0, 0.0);
}

void Sample_13_3::restoreGL()
{
	glPopAttrib();
}

bool Sample_13_3::sendMessage(int message, int mode, int x, int y)
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
			glGetIntegerv (GL_VIEWPORT, viewport);

			glSelectBuffer (BUFSIZE, selectBuf);
			(void) glRenderMode (GL_SELECT);

			glInitNames();
			glPushName(0);

			glMatrixMode (GL_PROJECTION);
			glPushMatrix ();
			glLoadIdentity ();
			/*  create 5x5 pixel picking region near cursor location	*/
			gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3] - y),
					5.0, 5.0, viewport);
			gluOrtho2D (0.0, 3.0, 0.0, 3.0);
			drawSquares (GL_SELECT);

			glMatrixMode (GL_PROJECTION);
			glPopMatrix ();

			hits = glRenderMode (GL_RENDER);
			processHits (hits, selectBuf);
		}
		break;
	default:
		return false;
		break;
	}

	return true;
}

/*  The nine squares are drawn.  In selection mode, each
 *  square is given two names:  one for the row and the
 *  other for the column on the grid.  The color of each
 *  square is determined by its position on the grid, and
 *  the value in the board[][] array.
 */
void Sample_13_3::drawSquares(GLenum mode)
{
	GLuint i, j;
	for (i = 0; i < 3; i++) {
		if (mode == GL_SELECT)
			glLoadName (i);
		for (j = 0; j < 3; j ++) {
			if (mode == GL_SELECT)
				glPushName (j);
			glColor3f ((GLfloat) i/3.0, (GLfloat) j/3.0,
					(GLfloat) m_board[i][j]/3.0);
			glRecti (i, j, i+1, j+1);
			if (mode == GL_SELECT)
				glPopName ();
		}
	}
}

/*  processHits prints out the contents of the
 *  selection array.
 */
void Sample_13_3::processHits (GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint ii, jj, names, *ptr;

	printf ("hits = %d\n", hits);
	ptr = (GLuint *) buffer;
	for (i = 0; i < hits; i++) {	/*  for each hit  */
		names = *ptr;
		printf (" number of names for this hit = %d\n", names); ptr++;
		printf("  z1 is %g;", (float) *ptr/0x7fffffff); ptr++;
		printf(" z2 is %g\n", (float) *ptr/0x7fffffff); ptr++;
		printf ("   names are ");
		for (j = 0; j < names; j++) { /*  for each name */
			printf ("%d ", *ptr);
			if (j == 0)  /*  set row and column  */
				ii = *ptr;
			else if (j == 1)
				jj = *ptr;
			ptr++;
		}
		printf ("\n");
		m_board[ii][jj] = (m_board[ii][jj] + 1) % 3;
	}
}

