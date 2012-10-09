/*
 * OGLConsumer.h
 *
 *  Created on: Oct 1, 2012
 *      Author: Andrew Zhabura
 */

#ifndef OGL_CONSUMER_H_
#define OGL_CONSUMER_H_

class Lesson;

class OGL_Consumer
{
public:
	OGL_Consumer();
	~OGL_Consumer();
	void initGL();
	void setLesson(unsigned int lessonNum);
	void reshape(unsigned int width, unsigned int height);
	void drawGLScene();

private:
	Lesson ** m_lesson;
	unsigned int m_lessonNum;
};

#endif // OGL_CONSUMER_H_
