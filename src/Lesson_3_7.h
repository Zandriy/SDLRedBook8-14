/*
 * Lesson_3_7.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_7_H_
#define LESSON_3_7_H_

#include "Lesson.h"

class Lesson_3_7 : public Lesson
{
public:
	Lesson_3_7();
	virtual ~Lesson_3_7();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"3-7. Robot(s-S, e-E)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

private:
	void draw();

	int m_shoulder;
	int m_elbow;
};

#endif /* LESSON_3_7_H_ */
