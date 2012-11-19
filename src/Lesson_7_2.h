/*
 * Lesson_7_2.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_7_2_H_
#define LESSON_7_2_H_

#include "Lesson.h"

class Lesson_7_2 : public Lesson
{
public:
	Lesson_7_2();
	virtual ~Lesson_7_2();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"7-2. List";
	}

private:
	void draw();
	void drawLine();

	GLuint m_listName;
};

#endif /* LESSON_7_2_H_ */
