/*
 * Lesson_2_6.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_6_H_
#define LESSON_2_6_H_

#include "Lesson.h"

class Lesson_2_6 : public Lesson
{
public:
	Lesson_2_6();
	virtual ~Lesson_2_6();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-6. Polys (stipple)";
	}

private:
	void draw();
};

#endif /* LESSON_2_6_H_ */
