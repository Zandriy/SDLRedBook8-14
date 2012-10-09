/*
 * Lesson_2_9.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_9_H_
#define LESSON_2_9_H_

#include "Lesson.h"

class Lesson_2_9 : public Lesson
{
public:
	Lesson_2_9();
	virtual ~Lesson_2_9();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();

private:
	void draw();
};

#endif /* LESSON_2_9_H_ */
