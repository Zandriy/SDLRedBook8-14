/*
 * OGLInspector.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#ifndef OGLInspector_H
#define OGLInspector_H

#include <cstring>
#include <string>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class OGLInspector
{
public:
	OGLInspector();
	~OGLInspector();

	bool isExtSupported(const std::string& extName);
	bool PBOSupported();
	bool ImagingSupported();
private:
	std::string m_extNames;
};


#endif
