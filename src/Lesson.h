/*
 * Lesson.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_H_
#define LESSON_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class Lesson
{
public:
	virtual ~Lesson(){}

	virtual void reshape(int width, int height) = 0;
	virtual void drawGLScene() = 0;
	virtual char* getName() = 0;

	virtual bool sendMessage(int message, int mode, int x, int y)
	{
		return false;
	}
};

#endif /* LESSON_2_10_H_ */
