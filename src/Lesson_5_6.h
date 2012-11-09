/*
 * Lesson_5_6.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_5_6_H_
#define LESSON_5_6_H_

#include "Lesson.h"

class Lesson_5_6 : public Lesson
{
public:
	Lesson_5_6();
	virtual ~Lesson_5_6();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"5-6. Move Light";
	}
private:
	void draw();
	void light_moving();

	int m_spin;
	double m_rotFact;
};

#endif /* LESSON_5_6_H_ */
