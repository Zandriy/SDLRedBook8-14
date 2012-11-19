/*
 * Lesson_7_7.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_7_7_H_
#define LESSON_7_7_H_

#include "Lesson.h"

class Lesson_7_7 : public Lesson
{
public:
	Lesson_7_7();
	virtual ~Lesson_7_7();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"7-7. List with glPushAttrib()";
	}

private:
	void draw();
	void drawLine();

	GLuint m_listName;
};

#endif /* LESSON_7_7_H_ */
