/*
 * Lesson_5_7.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_7_H_
#define LESSON_5_7_H_

#include "Lesson.h"

class Lesson_5_7 : public Lesson
{
public:
	Lesson_5_7();
	virtual ~Lesson_5_7();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-7. Move Light with Object";
	}
private:
	void draw();
	void changeCameraPos();

	GLdouble m_ex, m_ey, m_ez, m_upx, m_upy, m_upz;
	int m_action;
	bool m_bWire;
};

#endif /* LESSON_5_7_H_ */
