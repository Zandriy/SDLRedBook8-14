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

	virtual bool sendMessage(unsigned int  message, unsigned int mode);

private:
	void draw();
	void wireSphere(GLdouble radius,GLint slices, GLint stacks);

	int m_year;
	int m_day;
};

#endif /* LESSON_3_6_H_ */
