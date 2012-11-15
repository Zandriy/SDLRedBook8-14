/*
 * Lesson_6_3.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_3_H_
#define LESSON_6_3_H_

#include "Lesson.h"

class Lesson_6_3 : public Lesson
{
public:
	Lesson_6_3();
	virtual ~Lesson_6_3();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-3. aargb (r-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();

	float m_rotAngle;
};

#endif /* LESSON_6_3_H_ */
