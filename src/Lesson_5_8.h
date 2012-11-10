/*
 * Lesson_5_8.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_8_H_
#define LESSON_5_8_H_

#include "Lesson.h"

class Lesson_5_8 : public Lesson
{
public:
	Lesson_5_8();
	virtual ~Lesson_5_8();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-8. Two Side Lighting";
	}
private:
	void draw();
};

#endif /* LESSON_5_8_H_ */
