/*
 * Sample_12_8.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_8.h"
#include "OGLShapes.h"
#include <stdio.h>

#include <SDL/SDL.h>

#ifndef CALLBACK
#define CALLBACK
#endif

void CALLBACK nurbsErr(GLenum errorCode)
{
	const GLubyte *estring;

	estring = gluErrorString(errorCode);
	fprintf (stderr, "Nurbs Error: %s\n", estring);
}

Sample_12_8::Sample_12_8()
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

Sample_12_8::~Sample_12_8()
{
	gluDeleteNurbsRenderer(m_theNurb);
}

void Sample_12_8::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective (45.0, (GLdouble)w/(GLdouble)h, 3.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
}

void Sample_12_8::draw()
{
	int i, j;

	GLfloat knots[8] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
	GLfloat edgePt[5][2] = /* counter clockwise */
	{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}, {0.0, 0.0}};
	GLfloat curvePt[4][2] = /* clockwise */
	{{0.25, 0.5}, {0.25, 0.75}, {0.75, 0.75}, {0.75, 0.5}};
	GLfloat curveKnots[8] =
	{0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
	GLfloat pwlPt[4][2] = /* clockwise */
	{{0.75, 0.5}, {0.5, 0.25}, {0.25, 0.5}};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(330.0, 1.,0.,0.);
	glScalef (0.5, 0.5, 0.5);

	gluBeginSurface(m_theNurb);
	gluNurbsSurface(m_theNurb, 8, knots, 8, knots,
			4 * 3, 3, &m_ctlpoints[0][0][0],
			4, 4, GL_MAP2_VERTEX_3);
	gluBeginTrim (m_theNurb);
	gluPwlCurve (m_theNurb, 5, &edgePt[0][0], 2, GLU_MAP1_TRIM_2);
	gluEndTrim (m_theNurb);
	gluBeginTrim (m_theNurb);
	gluNurbsCurve (m_theNurb, 8, curveKnots, 2,
			&curvePt[0][0], 4, GLU_MAP1_TRIM_2);
	gluPwlCurve (m_theNurb, 3, &pwlPt[0][0], 2, GLU_MAP1_TRIM_2);
	gluEndTrim (m_theNurb);
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

void Sample_12_8::initGL()
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

	gluNurbsProperty(m_theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
	gluNurbsProperty(m_theNurb, GLU_DISPLAY_MODE, GLU_FILL);
	gluNurbsCallback(m_theNurb, GLU_ERROR,
			(GLvoid (*) ()) &nurbsErr);
}

void Sample_12_8::restoreGL()
{
	glPopAttrib();
}

bool Sample_12_8::sendMessage(int message, int mode, int x, int y)
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
