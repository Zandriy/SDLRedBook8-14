/*
 * Lesson_2_15ex.h
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_15ex_H_
#define LESSON_2_15ex_H_

#include "Lesson.h"

class Lesson_2_15ex : public Lesson
{
public:
	Lesson_2_15ex();
	virtual ~Lesson_2_15ex();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-15ex. Icosahedron-Sphere";
	}

private:
	void draw();
};

#endif /* LESSON_2_15ex_H_ */
