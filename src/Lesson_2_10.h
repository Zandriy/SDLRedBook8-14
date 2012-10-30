/*
 * Lesson_2_10.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_10_H_
#define LESSON_2_10_H_

#include "Lesson.h"

class Lesson_2_10 : public Lesson
{
public:
	Lesson_2_10();
	virtual ~Lesson_2_10();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-10. glArrayElement";
	}

private:
	void draw();
};

#endif /* LESSON_2_10_H_ */
