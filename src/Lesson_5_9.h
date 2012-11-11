/*
 * Lesson_5_9.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_9_H_
#define LESSON_5_9_H_

#include "Lesson.h"

class Lesson_5_9 : public Lesson
{
public:
	Lesson_5_9();
	virtual ~Lesson_5_9();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-9. Different material properties";
	}
private:
	void draw();
};

#endif /* LESSON_5_9_H_ */
