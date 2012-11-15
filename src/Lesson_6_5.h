/*
 * Lesson_6_5.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_5_H_
#define LESSON_6_5_H_

#include "Lesson.h"

class Lesson_6_5 : public Lesson
{
public:
	Lesson_6_5();
	virtual ~Lesson_6_5();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-3. fog (f-F)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();

	void renderSphere (GLfloat x, GLfloat y, GLfloat z);

	GLint m_fogMode;
};

#endif /* LESSON_6_5_H_ */
