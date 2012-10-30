/*
 * Lesson_5_1.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_1_H_
#define LESSON_5_1_H_

#include "Lesson.h"

class Lesson_5_1 : public Lesson
{
public:
	Lesson_5_1();
	virtual ~Lesson_5_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-1. Light";
	}
private:
	void draw();
};

#endif /* LESSON_5_1_H_ */
