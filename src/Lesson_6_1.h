/*
 * Lesson_6_1.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_1_H_
#define LESSON_6_1_H_

#include "Lesson.h"

class Lesson_6_1 : public Lesson
{
public:
	Lesson_6_1();
	virtual ~Lesson_6_1();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-1. Alpha (t-T)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();

	void drawLeftTriangle();
	void drawRightTriangle();

	bool m_leftFirst;
};

#endif /* LESSON_6_1_H_ */
