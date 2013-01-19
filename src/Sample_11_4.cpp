/*
 * Sample_11_4.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_11_4.h"
#include "OGLShapes.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef CALLBACK
#define CALLBACK
#endif


void CALLBACK errorQCallback(GLenum errorCode)
{
	const GLubyte *estring;

	estring = gluErrorString(errorCode);
	fprintf(stderr, "Quadric Error: %s\n", estring);
	exit(0);
}


Sample_11_4::Sample_11_4()
:	m_startList(0)
,	m_qobj(NULL)
{
}

Sample_11_4::~Sample_11_4()
{
}

void Sample_11_4::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
				2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.5*(GLfloat)w/(GLfloat)h,
				2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_11_4::draw()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glShadeModel (GL_SMOOTH);
	glTranslatef(-1.0, -1.0, 0.0);
	glCallList(m_startList);

	glShadeModel (GL_FLAT);
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
	glRotatef(300.0, 1.0, 0.0, 0.0);
	glCallList(m_startList+1);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(2.0, -2.0, 0.0);
	glCallList(m_startList+2);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, 2.0, 0.0);
	glCallList(m_startList+3);

	glPopMatrix();
}

void Sample_11_4::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	/*  Create 4 display lists, each with a different quadric object.
	 *  Different drawing styles and surface normal specifications
	 *  are demonstrated.
	 */
	m_startList = glGenLists(4);
	m_qobj = gluNewQuadric();
	gluQuadricCallback(m_qobj, GLU_ERROR,
			(GLvoid (*) ( )) &errorQCallback);

	gluQuadricDrawStyle(m_qobj, GLU_FILL); /* smooth shaded */
	gluQuadricNormals(m_qobj, GLU_SMOOTH);
	glNewList(m_startList, GL_COMPILE);
	gluSphere(m_qobj, 0.75, 15, 10);
	glEndList();

	gluQuadricDrawStyle(m_qobj, GLU_FILL); /* flat shaded */
	gluQuadricNormals(m_qobj, GLU_FLAT);
	glNewList(m_startList+1, GL_COMPILE);
	gluCylinder(m_qobj, 0.5, 0.3, 1.0, 15, 5);
	glEndList();

	gluQuadricDrawStyle(m_qobj, GLU_LINE); /* all polygons wireframe */
	gluQuadricNormals(m_qobj, GLU_NONE);
	glNewList(m_startList+2, GL_COMPILE);
	gluDisk(m_qobj, 0.25, 1.0, 20, 4);
	glEndList();

	gluQuadricDrawStyle(m_qobj, GLU_SILHOUETTE); /* boundary only  */
	gluQuadricNormals(m_qobj, GLU_NONE);
	glNewList(m_startList+3, GL_COMPILE);
	gluPartialDisk(m_qobj, 0.0, 1.0, 20, 4, 0.0, 225.0);
	glEndList();
}

void Sample_11_4::restoreGL()
{
	gluDeleteQuadric(m_qobj);
	glPopAttrib();
}
