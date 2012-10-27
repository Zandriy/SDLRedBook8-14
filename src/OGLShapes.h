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
	static void wireSphere(GLdouble radius,GLint slices, GLint stacks);
private:
	OGLShapes();
	OGLShapes(const OGLShapes&);
	~OGLShapes();
};


#endif /* OGLShapes_H_ */
