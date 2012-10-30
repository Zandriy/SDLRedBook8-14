/*
 * Lesson_3_6.h
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_6_H_
#define LESSON_3_6_H_

#include "Lesson.h"

class Lesson_3_6 : public Lesson
{
public:
	Lesson_3_6();
	virtual ~Lesson_3_6();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"3-6. Planet(y-Y,d-D)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

private:
	void draw();

	int m_year;
	int m_day;
};

#endif /* LESSON_3_6_H_ */
