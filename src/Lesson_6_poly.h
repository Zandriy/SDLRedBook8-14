/*
 * Lesson_6_poly.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_poly_H_
#define LESSON_6_poly_H_

#include "Lesson.h"

class Lesson_6_poly : public Lesson
{
public:
	Lesson_6_poly();
	virtual ~Lesson_6_poly();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-poly. aapoly (t-T)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();
	void drawCube(GLdouble x0, GLdouble x1, GLdouble y0, GLdouble y1,
	        GLdouble z0, GLdouble z1);

	GLboolean m_polySmooth;
};

#endif /* LESSON_6_poly_H_ */
