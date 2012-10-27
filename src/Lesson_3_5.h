/*
 * Lesson_3_5.h
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_5_H_
#define LESSON_3_5_H_

#include "Lesson.h"

class Lesson_3_5 : public Lesson
{
public:
	Lesson_3_5();
	virtual ~Lesson_3_5();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();

private:
	void draw();
};

#endif /* LESSON_3_5_H_ */
