/*
 * Lesson_2_11.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_11_H_
#define LESSON_2_11_H_

#include "Lesson.h"

class Lesson_2_11 : public Lesson
{
public:
	Lesson_2_11();
	virtual ~Lesson_2_11();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-11. glDrawElements";
	}

private:
	void draw();
};

#endif /* LESSON_2_11_H_ */
