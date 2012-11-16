/*
 * Lesson_6_2.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_2_H_
#define LESSON_6_2_H_

#include "Lesson.h"

class Lesson_6_2 : public Lesson
{
public:
	Lesson_6_2();
	virtual ~Lesson_6_2();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-2. Alpha3D (a-A, r-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();
	void animate();

	bool m_stop;
	float m_solidZ, m_transparentZ;
	GLuint m_sphereList, m_cubeList;
};

#endif /* LESSON_6_2_H_ */
