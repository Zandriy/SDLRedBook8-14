/*
 * Lesson_1_2.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_1_2_H_
#define LESSON_1_2_H_

#include "Lesson.h"

class Lesson_1_2 : public Lesson
{
public:
	Lesson_1_2();
	virtual ~Lesson_1_2();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"1-2. Hello";
	}

private:
	void draw();
};

#endif /* LESSON_1_2_H_ */
