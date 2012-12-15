/*
 * OGLInspector.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#include <algorithm>

#include "OGLInspector.h"

OGLInspector::OGLInspector()
{
	char* str = 0;
	char* token = 0;

	str = (char*)glGetString(GL_EXTENSIONS);

	// split extensions
	if(!str) return;

	token = strtok((char*)str, " ");
	while(token)
	{
		m_extNames.insert(token);    // put a extension into struct
		token = strtok(0, " ");               // next token
	}
}

OGLInspector::~OGLInspector()
{
	m_extNames.clear();
}

bool OGLInspector::isExtSupported(const std::string& extName)
{
	if ( m_extNames.find(extName) != m_extNames.end() )
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
