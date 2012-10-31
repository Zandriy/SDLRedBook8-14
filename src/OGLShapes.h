/*
 * OGLShapes.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef OGLShapes_H_
#define OGLShapes_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class OGLShapes
{
public:
	static void wireCube(GLdouble size);
	static void solidCube(GLdouble size);
	static void wireSphere(GLdouble radius, GLint slices, GLint stacks);
	static void solidSphere(GLdouble radius, GLint slices, GLint stacks);
	static void wireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
	static void solidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
private:
	OGLShapes();
	OGLShapes(const OGLShapes&);
	~OGLShapes();

	static void spherePoints(GLdouble radius,GLint slices, GLint stacks, GLfloat *points);
};


#endif /* OGLShapes_H_ */
