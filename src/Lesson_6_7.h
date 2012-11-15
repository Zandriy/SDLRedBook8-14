/*
 * Lesson_6_7.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_7_H_
#define LESSON_6_7_H_

#include "Lesson.h"

class Lesson_6_7 : public Lesson
{
public:
	Lesson_6_7();
	virtual ~Lesson_6_7();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-7. Polygon offset";
	}
private:
	void draw();
};

#endif /* LESSON_6_7_H_ */
