/*
 * Lesson_3_8.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_3_8_H_
#define LESSON_3_8_H_

#include "Lesson.h"

class Lesson_3_8 : public Lesson
{
public:
	Lesson_3_8();
	virtual ~Lesson_3_8();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"3-8. gluUnProject";
	}

	bool sendMessage(int message, int mode, int x, int y);
};

#endif /* LESSON_3_8_H_ */
