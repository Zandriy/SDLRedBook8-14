/*
 * Lesson_1_3.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_1_3_H_
#define LESSON_1_3_H_

#include "Lesson.h"

class Lesson_1_3 : public Lesson
{
public:
	Lesson_1_3();
	virtual ~Lesson_1_3();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"1-3. Double Buffer";
	}

private:
	void draw();
	void spinDisplay();

	GLfloat m_spin;
};

#endif /* LESSON_1_3_H_ */
