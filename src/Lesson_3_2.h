/*
 * Lesson_3_2.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_2_H_
#define LESSON_3_2_H_

#include "Lesson.h"

class Lesson_3_2 : public Lesson
{
public:
	Lesson_3_2();
	virtual ~Lesson_3_2();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"3-2. Model Transformation";
	}

private:
	void draw();
	void draw_triangle();
};

#endif /* LESSON_3_2_H_ */
