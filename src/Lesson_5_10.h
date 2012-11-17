/*
 * Lesson_5_10.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_10_H_
#define LESSON_5_10_H_

#include "Lesson.h"

class Lesson_5_10 : public Lesson
{
public:
	Lesson_5_10();
	virtual ~Lesson_5_10();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-10. ColorMat (mouse L-M-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();

	GLfloat * m_diffuseMaterial;
};

#endif /* LESSON_5_10_H_ */
