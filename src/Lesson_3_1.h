/*
 * Lesson_3_1.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_1_H_
#define LESSON_3_1_H_

#include "Lesson.h"

class Lesson_3_1 : public Lesson
{
public:
	Lesson_3_1();
	virtual ~Lesson_3_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"3-1. Cube(gluLookAt)";
	}

private:
	void draw();
};

#endif /* LESSON_3_1_H_ */
