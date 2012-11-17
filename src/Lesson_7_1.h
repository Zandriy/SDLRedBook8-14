/*
 * Lesson_7_1.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_7_1_H_
#define LESSON_7_1_H_

#include "Lesson.h"

class Lesson_7_1 : public Lesson
{
public:
	Lesson_7_1();
	virtual ~Lesson_7_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"7-1. torus (x-X, y-Y, i-I)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();
	void torus(int numc, int numt);

	GLuint m_theTorus;
};

#endif /* LESSON_7_1_H_ */
