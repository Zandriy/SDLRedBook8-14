/*
 * Sample.h
 *
 *  Created on: Dec 6, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_H_
#define Sample_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class Sample
{
public:
	virtual ~Sample(){}

	virtual void reshape(int width, int height) = 0;
	virtual char* getName() = 0;

	virtual bool sendMessage(int message, int mode, int x, int y)
	{
		return false;
	}

	void drawGLScene()
	{
		initGL();
		draw();
		restoreGL();
	}

protected:
	virtual void draw() = 0;
	virtual void initGL() = 0;
	virtual void restoreGL() = 0;
};

#endif /* Sample_2_10_H_ */
