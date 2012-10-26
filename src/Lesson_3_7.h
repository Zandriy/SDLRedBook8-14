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

	virtual bool sendMessage(unsigned int  message, unsigned int mode);

private:
	void draw();
	void wireCube(GLdouble size);

	int m_shoulder;
	int m_elbow;
};

#endif /* LESSON_3_7_H_ */
