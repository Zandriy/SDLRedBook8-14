/*
 * Sample_12_7.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_7.h"
#include "OGLShapes.h"
#include <stdio.h>

#include <SDL/SDL.h>

#ifndef CALLBACK
#define CALLBACK
#endif

void CALLBACK errorCallbackNURBS(GLenum errorCode)
{
	const GLubyte *estring;

	estring = gluErrorString(errorCode);
	fprintf (stderr, "Nurbs Error: %s\n", estring);
}

void CALLBACK beginCallbackNURBS(GLenum whichType)
{
   glBegin (whichType);  /*  resubmit rendering directive  */
   printf ("glBegin(");
   switch (whichType) {  /*  print diagnostic message  */
      case GL_LINES:
	 printf ("GL_LINES)\n");
	 break;
      case GL_LINE_LOOP:
	 printf ("GL_LINE_LOOP)\n");
	 break;
      case GL_LINE_STRIP:
	 printf ("GL_LINE_STRIP)\n");
	 break;
      case GL_TRIANGLES:
	 printf ("GL_TRIANGLES)\n");
	 break;
      case GL_TRIANGLE_STRIP:
	 printf ("GL_TRIANGLE_STRIP)\n");
	 break;
      case GL_TRIANGLE_FAN:
	 printf ("GL_TRIANGLE_FAN)\n");
	 break;
      case GL_QUADS:
	 printf ("GL_QUADS)\n");
	 break;
      case GL_QUAD_STRIP:
	 printf ("GL_QUAD_STRIP)\n");
	 break;
      case GL_POLYGON:
	 printf ("GL_POLYGON)\n");
	 break;
      default:
	 break;
   }
}

void CALLBACK endCallbackNURBS()
{
   glEnd();  /*  resubmit rendering directive  */
   printf ("glEnd()\n");
}

void CALLBACK vertexCallbackNURBS(GLfloat *vertex)
{
   glVertex3fv(vertex);  /*  resubmit rendering directive  */
   printf ("glVertex3f (%5.3f, %5.3f, %5.3f)\n",
	   vertex[0], vertex[1], vertex[2]);
}

void CALLBACK normalCallbackNURBS(GLfloat *normal)
{
   glNormal3fv(normal);  /*  resubmit rendering directive  */
   printf ("glNormal3f (%5.3f, %5.3f, %5.3f)\n",
           normal[0], normal[1], normal[2]);
}

Sample_12_7::Sample_12_7()
: m_showPoints(false)
, m_theNurb(gluNewNurbsRenderer())
{
	/*
	 *  Initializes the control points of the surface to a small hill.
	 *  The control points range from -3 to +3 in x, y, and z
	 */
	int u, v;
	for (u = 0; u < 4; u++) {
		for (v = 0; v < 4; v++) {
			m_ctlpoints[u][v][0] = 2.0*((GLfloat)u - 1.5);
			m_ctlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);

			if ( (u == 1 || u == 2) && (v == 1 || v == 2))
				m_ctlpoints[u][v][2] = 3.0;
			else
				m_ctlpoints[u][v][2] = -3.0;
		}
	}
}

Sample_12_7::~Sample_12_7()
{
	gluDeleteNurbsRenderer(m_theNurb);
}

void Sample_12_7::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective (45.0, (GLdouble)w/(GLdouble)h, 3.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
}

void Sample_12_7::draw()
{
	GLfloat knots[8] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(330.0, 1.,0.,0.);
	glScalef (0.5, 0.5, 0.5);

	gluBeginSurface(m_theNurb);
	gluNurbsSurface(m_theNurb,
			8, knots, 8, knots,
			4 * 3, 3, &m_ctlpoints[0][0][0],
			4, 4, GL_MAP2_VERTEX_3);
	gluEndSurface(m_theNurb);

	if (m_showPoints) {
		glPointSize(5.0);
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POINTS);
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				glVertex3f(m_ctlpoints[i][j][0],
						m_ctlpoints[i][j][1], m_ctlpoints[i][j][2]);
			}
		}
		glEnd();
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();
}

void Sample_12_7::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);


	   gluNurbsProperty(m_theNurb, GLU_NURBS_MODE,
			    GLU_NURBS_TESSELLATOR);
	   gluNurbsProperty(m_theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
	   gluNurbsProperty(m_theNurb, GLU_DISPLAY_MODE, GLU_FILL);
	   gluNurbsCallback(m_theNurb, GLU_ERROR, (GLvoid (*) ()) &errorCallbackNURBS);
	   gluNurbsCallback(m_theNurb, GLU_NURBS_BEGIN, (GLvoid (*) ()) &beginCallbackNURBS);
	   gluNurbsCallback(m_theNurb, GLU_NURBS_VERTEX, (GLvoid (*) ()) &vertexCallbackNURBS);
	   gluNurbsCallback(m_theNurb, GLU_NURBS_NORMAL, (GLvoid (*) ()) &normalCallbackNURBS);
	   gluNurbsCallback(m_theNurb, GLU_NURBS_END, endCallbackNURBS);
}

void Sample_12_7::restoreGL()
{
	glPopAttrib();
}

bool Sample_12_7::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_c:
		m_showPoints = !m_showPoints;;
		break;
	default:
		return false;
		break;
	}

	return true;
}
