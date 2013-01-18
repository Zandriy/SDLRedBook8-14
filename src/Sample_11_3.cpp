/*
 * Sample_11_3.cpp
 *
 *  Created on: Jan 17, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_11_3.h"
#include "OGLShapes.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef CALLBACK
#define CALLBACK
#endif

void CALLBACK beginCallback(GLenum which)
{
	glBegin(which);
}

void CALLBACK errorCallback(GLenum errorCode)
{
	const GLubyte *estring;

	estring = gluErrorString(errorCode);
	fprintf(stderr, "Tessellation Error: %s\n", estring);
	exit(0);
}

void CALLBACK endCallback(void)
{
	glEnd();
}

void CALLBACK vertexCallback(GLvoid *vertex)
{
	const GLdouble *pointer;

	pointer = (GLdouble *) vertex;
	glColor3dv(pointer+3);
	glVertex3dv( (GLdouble *) vertex );
}

/*  combineCallback is used to create a new vertex when edges
 *  intersect.  coordinate location is trivial to calculate,
 *  but weight[4] may be used to average color, normal, or texture
 *  coordinate data.  In this program, color is weighted.
 */
void CALLBACK combineCallback(GLdouble coords[3],
		GLdouble *vertex_data[4],
		GLfloat weight[4], GLdouble **dataOut )
{
	GLdouble *vertex;
	int i;

	vertex = (GLdouble *) malloc(6 * sizeof(GLdouble));

	vertex[0] = coords[0];
	vertex[1] = coords[1];
	vertex[2] = coords[2];
	for (i = 3; i < 6; i++)
		vertex[i] = weight[0] * vertex_data[0][i]
		                                       + weight[1] * vertex_data[1][i]
		                                                                    + weight[2] * vertex_data[2][i]
		                                                                                                 + weight[3] * vertex_data[3][i];
	*dataOut = vertex;
}


Sample_11_3::Sample_11_3()
:	m_startList(0)
,	m_tobj(NULL)
{
}

Sample_11_3::~Sample_11_3()
{
}

void Sample_11_3::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void Sample_11_3::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glCallList(m_startList);
	glCallList(m_startList + 1);
}

void Sample_11_3::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	GLdouble rect[4][3] = {50.0, 50.0, 0.0,
			200.0, 50.0, 0.0,
			200.0, 200.0, 0.0,
			50.0, 200.0, 0.0};
	GLdouble tri[3][3] = {75.0, 75.0, 0.0,
			125.0, 175.0, 0.0,
			175.0, 75.0, 0.0};
	GLdouble star[5][6] = {250.0, 50.0, 0.0, 1.0, 0.0, 1.0,
			325.0, 200.0, 0.0, 1.0, 1.0, 0.0,
			400.0, 50.0, 0.0, 0.0, 1.0, 1.0,
			250.0, 150.0, 0.0, 1.0, 0.0, 0.0,
			400.0, 150.0, 0.0, 0.0, 1.0, 0.0};

	m_startList = glGenLists(2);

	m_tobj = gluNewTess();
	gluTessCallback(m_tobj, GLU_TESS_VERTEX,
			(GLvoid (*) ( )) &glVertex3dv);
	gluTessCallback(m_tobj, GLU_TESS_BEGIN,
			(GLvoid (*) ( )) &beginCallback);
	gluTessCallback(m_tobj, GLU_TESS_END,
			(GLvoid (*) ( )) &endCallback);
	gluTessCallback(m_tobj, GLU_TESS_ERROR,
			(GLvoid (*) ( )) &errorCallback);

	/*  rectangle with triangular hole inside  */
	glNewList(m_startList, GL_COMPILE);
	glShadeModel(GL_FLAT);
	gluTessBeginPolygon(m_tobj, NULL);
	gluTessBeginContour(m_tobj);
	gluTessVertex(m_tobj, rect[0], rect[0]);
	gluTessVertex(m_tobj, rect[1], rect[1]);
	gluTessVertex(m_tobj, rect[2], rect[2]);
	gluTessVertex(m_tobj, rect[3], rect[3]);
	gluTessEndContour(m_tobj);
	gluTessBeginContour(m_tobj);
	gluTessVertex(m_tobj, tri[0], tri[0]);
	gluTessVertex(m_tobj, tri[1], tri[1]);
	gluTessVertex(m_tobj, tri[2], tri[2]);
	gluTessEndContour(m_tobj);
	gluTessEndPolygon(m_tobj);
	glEndList();

	gluTessCallback(m_tobj, GLU_TESS_VERTEX,
			(GLvoid (*) ( )) &vertexCallback);
	gluTessCallback(m_tobj, GLU_TESS_BEGIN,
			(GLvoid (*) ( )) &beginCallback);
	gluTessCallback(m_tobj, GLU_TESS_END,
			endCallback);
	gluTessCallback(m_tobj, GLU_TESS_ERROR,
			(GLvoid (*) ( )) &errorCallback);
	gluTessCallback(m_tobj, GLU_TESS_COMBINE,
			(GLvoid (*) ( )) &combineCallback);

	/*  smooth shaded, self-intersecting star  */
	glNewList(m_startList + 1, GL_COMPILE);
	glShadeModel(GL_SMOOTH);
	gluTessProperty(m_tobj, GLU_TESS_WINDING_RULE,
			GLU_TESS_WINDING_POSITIVE);
	gluTessBeginPolygon(m_tobj, NULL);
	gluTessBeginContour(m_tobj);
	gluTessVertex(m_tobj, star[0], star[0]);
	gluTessVertex(m_tobj, star[1], star[1]);
	gluTessVertex(m_tobj, star[2], star[2]);
	gluTessVertex(m_tobj, star[3], star[3]);
	gluTessVertex(m_tobj, star[4], star[4]);
	gluTessEndContour(m_tobj);
	gluTessEndPolygon(m_tobj);
	glEndList();
}

void Sample_11_3::restoreGL()
{
	gluDeleteTess(m_tobj);
	glPopAttrib();
}
