/*
 * Lesson_2_5.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_5_H_
#define LESSON_2_5_H_

#include "Lesson.h"

class Lesson_2_5 : public Lesson
{
public:
	Lesson_2_5();
	virtual ~Lesson_2_5();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-5. Lines";
	}

private:
	void draw();
};

#endif /* LESSON_2_5_H_ */
