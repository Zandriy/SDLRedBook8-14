/*
 * Lesson_2_15.h
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_2_15_H_
#define LESSON_2_15_H_

#include "Lesson.h"

class Lesson_2_15 : public Lesson
{
public:
	Lesson_2_15();
	virtual ~Lesson_2_15();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"2-15. Icosahedron with normals";
	}

private:
	void draw();

	void normalize(float v[3]);
	void normcrossprod(float v1[3], float v2[3], float out[3]);
};

#endif /* LESSON_2_15_H_ */
