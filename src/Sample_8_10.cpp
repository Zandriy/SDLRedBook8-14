/*
 * Sample_8_10.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

/* 'a' -> GL_FUNC_ADD
 * 's' -> GL_FUNC_SUBTRACT
 * 'r' -> GL_FUNC_REVERSE_SUBTRACT
 * 'm' -> GL_MIN
 * 'x' -> GL_MAX
 */

#include "Sample_8_10.h"

#include <SDL/SDL.h>

#include "glext.h"
#include "OGLError.h"
#include "OGLInspector.h"

Sample_8_10::Sample_8_10()
{
}

Sample_8_10::~Sample_8_10()
{
}

void Sample_8_10::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_8_10::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glRectf(-0.5,-0.5,0.5,0.5);
}

void Sample_8_10::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(1.0,1.0,0.0,0.0);
	glBlendFunc(GL_ONE,GL_ONE);
	glEnable(GL_BLEND);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Sample_8_10::restoreGL()
{
	glPopAttrib();
}

bool Sample_8_10::sendMessage(int message, int mode, int x, int y)
{
	OGLError err;
	OGLInspector inspector;

	if (!inspector.ImagingSupported())
	{
		printf ("GL_ARB_imaging is not supported\n");
		return false;
	}

	switch (message) {
	case SDLK_a:
		glBlendEquation(GL_FUNC_ADD);
		break;
	case SDLK_s:
		glBlendEquation(GL_FUNC_SUBTRACT);
		break;
	case SDLK_r:
		glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
		break;
	case SDLK_m:
		glBlendEquation(GL_MIN);
		break;
	case SDLK_x:
		glBlendEquation(GL_MAX);
		break;
	default:
		return false;
		break;
	}

	if (!err.checkError())
		return false;

	drawGLScene();
	return true;
}
