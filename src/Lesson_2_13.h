/*
 * Lesson_2_13.h
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_13_H_
#define LESSON_2_13_H_

#include "Lesson.h"

class Lesson_2_13 : public Lesson
{
public:
	Lesson_2_13();
	virtual ~Lesson_2_13();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-13. Icosahedron";
	}

private:
	void draw();
};

#endif /* LESSON_2_13_H_ */
