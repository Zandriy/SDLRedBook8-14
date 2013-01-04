/*
 * Sample_10_3.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_10_3.h"
#include "OGLShapes.h"
#include "jitter.h"
#include <cmath>
#include <SDL/SDL.h>

#define PI_ 	3.14159265358979323846
#define ACSIZE	8
#define JITTER	j8

/* accFrustum()
 * The first 6 arguments are identical to the glFrustum() call.
 *
 * pixdx and pixdy are anti-alias jitter in pixels.
 * Set both equal to 0.0 for no anti-alias jitter.
 * eyedx and eyedy are depth-of field jitter in pixels.
 * Set both equal to 0.0 for no depth of field effects.
 *
 * focus is distance from eye to plane in focus.
 * focus must be greater than, but not equal to 0.0.
 *
 * Note that accFrustum() calls glTranslatef().  You will
 * probably want to insure that your ModelView matrix has been
 * initialized to identity before calling accFrustum().
 */
void accFrustum(GLdouble left, GLdouble right, GLdouble bottom,
		GLdouble top, GLdouble zNear, GLdouble zFar, GLdouble pixdx,
		GLdouble pixdy, GLdouble eyedx, GLdouble eyedy, GLdouble focus)
{
	GLdouble xwsize, ywsize;
	GLdouble dx, dy;
	GLint viewport[4];

	glGetIntegerv (GL_VIEWPORT, viewport);

	xwsize = right - left;
	ywsize = top - bottom;

	dx = -(pixdx*xwsize/(GLdouble) viewport[2] + eyedx*zNear/focus);
	dy = -(pixdy*ywsize/(GLdouble) viewport[3] + eyedy*zNear/focus);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum (left + dx, right + dx, bottom + dy, top + dy, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (-eyedx, -eyedy, 0.0);
}

/* accPerspective()
 *
 * The first 4 arguments are identical to the gluPerspective() call.
 * pixdx and pixdy are anti-alias jitter in pixels.
 * Set both equal to 0.0 for no anti-alias jitter.
 * eyedx and eyedy are depth-of field jitter in pixels.
 * Set both equal to 0.0 for no depth of field effects.
 *
 * focus is distance from eye to plane in focus.
 * focus must be greater than, but not equal to 0.0.
 *
 * Note that accPerspective() calls accFrustum().
 */
void accPerspective(GLdouble fovy, GLdouble aspect,
		GLdouble zNear, GLdouble zFar, GLdouble pixdx, GLdouble pixdy,
		GLdouble eyedx, GLdouble eyedy, GLdouble focus)
{
	GLdouble fov2,left,right,bottom,top;

	fov2 = ((fovy*PI_) / 180.0) / 2.0;

	top = zNear / (cos(fov2) / sin(fov2));
	bottom = -top;

	right = top * aspect;
	left = -right;

	accFrustum (left, right, bottom, top, zNear, zFar,
			pixdx, pixdy, eyedx, eyedy, focus);
}

Sample_10_3::Sample_10_3()
:	m_accDraw(ACSIZE)
{
}

Sample_10_3::~Sample_10_3()
{
}

void Sample_10_3::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void Sample_10_3::draw()
{
	GLint viewport[4];
	int jitter;

	glGetIntegerv (GL_VIEWPORT, viewport);

	glClear(GL_ACCUM_BUFFER_BIT);
	for (jitter = 0; jitter < m_accDraw; jitter++) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		accPerspective (50.0,
				(GLdouble) viewport[2]/(GLdouble) viewport[3],
				1.0, 15.0, JITTER[jitter].x, JITTER[jitter].y, 0.0, 0.0, 1.0);
		displayObjects ();
		glAccum(GL_ACCUM, 1.0/m_accDraw);
	}
	glAccum (GL_RETURN, 1.0);
}

void Sample_10_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.3, 0.0, 0.3, 0.0);
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_FLAT);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearAccum(0.0, 0.0, 0.0, 0.0);
}

void Sample_10_3::restoreGL()
{
	glPopAttrib();
}

bool Sample_10_3::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_a:
		m_accDraw = ACSIZE;
		break;
	case SDLK_n:
		m_accDraw = 1;
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_10_3::displayObjects()
{
	GLfloat torus_diffuse[] = { 0.7, 0.7, 0.0, 1.0 };
	GLfloat cube_diffuse[] = { 0.0, 0.7, 0.7, 1.0 };
	GLfloat sphere_diffuse[] = { 0.7, 0.0, 0.7, 1.0 };
	GLfloat octa_diffuse[] = { 0.7, 0.4, 0.4, 1.0 };

	glPushMatrix ();
	glTranslatef (0.0, 0.0, -5.0);
	glRotatef (30.0, 1.0, 0.0, 0.0);

	glPushMatrix ();
	glTranslatef (-0.80, 0.35, 0.0);
	glRotatef (100.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, torus_diffuse);
	OGLShapes::solidTorus (0.275, 0.85, 16, 16);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (-0.75, -0.50, 0.0);
	glRotatef (45.0, 0.0, 0.0, 1.0);
	glRotatef (45.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
	OGLShapes::solidCube (1.5);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0.75, 0.60, 0.0);
	glRotatef (30.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere_diffuse);
	OGLShapes::solidSphere (1.0, 16, 16);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0.70, -0.90, 0.25);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, octa_diffuse);
	OGLShapes::solidSphere (1.0, 4, 6);
	glPopMatrix ();

	glPopMatrix ();
}
