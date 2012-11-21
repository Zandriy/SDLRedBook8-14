/*
 * Lesson_8_1.h
 *
 *  Created on: Nov 22, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_8_1_H_
#define LESSON_8_1_H_

#include "Lesson.h"

class Lesson_8_1 : public Lesson
{
public:
	Lesson_8_1();
	virtual ~Lesson_8_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"8-1. DrawF";
	}

private:
	void draw();
};

#endif /* LESSON_8_1_H_ */
