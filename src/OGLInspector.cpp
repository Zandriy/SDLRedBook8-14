/*
 * OGLInspector.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#include <algorithm>
#include <iostream>

#include "OGLInspector.h"

OGLInspector::OGLInspector()
{
	char* str = 0;
	char* token = 0;

	m_extNames = (char*)glGetString(GL_EXTENSIONS);
}

OGLInspector::~OGLInspector()
{
	m_extNames.clear();
}

bool OGLInspector::isExtSupported(const std::string& extName)
{
	if ( m_extNames.find(extName) != std::string::npos )
		return true;

	return false;
}

bool OGLInspector::PBOSupported()
{
	return isExtSupported("GL_ARB_pixel_buffer_object");
}

bool OGLInspector::ImagingSupported()
{
	return isExtSupported("GL_ARB_imaging");
}
