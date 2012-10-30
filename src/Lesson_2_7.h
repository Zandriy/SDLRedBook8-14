/*
 * Lesson_2_7.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_7_H_
#define LESSON_2_7_H_

#include "Lesson.h"

class Lesson_2_7 : public Lesson
{
public:
	Lesson_2_7();
	virtual ~Lesson_2_7();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-7. Edge Flag";
	}

private:
	void draw();

	GLfloat *	V0;
	GLfloat *	V1;
	GLfloat *	V2;
};

#endif /* LESSON_2_7_H_ */
