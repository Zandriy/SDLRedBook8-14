/*
 * Lesson_4_1.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_4_1_H_
#define LESSON_4_1_H_

#include "Lesson.h"

class Lesson_4_1 : public Lesson
{
public:
	Lesson_4_1();
	virtual ~Lesson_4_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"4-1. Smooth";
	}
private:
	void draw();
};

#endif /* LESSON_4_1_H_ */
