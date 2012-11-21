/*
 * OGLConsumer.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: Andrew Zhabura
 */

#include "OGLConsumer.h"

#include "Lesson_8_1.h"

#define LESSON_QTY 1

OGL_Consumer::OGL_Consumer()
:	m_lesson(new Lesson * [LESSON_QTY])
,	m_lessonNum(0)
{
	m_lesson[0] = new Lesson_8_1;
}

OGL_Consumer::~OGL_Consumer()
{
	for (int i = 0; i < LESSON_QTY; ++i)
	{
		if (m_lesson[i])
			delete m_lesson[i];
	}
}

// general OpenGL initialization function
void OGL_Consumer::initGL()
{
	// Enable smooth shading
	glShadeModel( GL_SMOOTH );

	// Set the background black
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	// Depth buffer setup
	glClearDepth( 1.0f );

	// Enables Depth Testing
	glEnable( GL_DEPTH_TEST );

	// Enables Light
	//glEnable( GL_LIGHTING );

	// The Type Of Depth Test To Do
	glDepthFunc( GL_LEQUAL );

	// Really Nice Perspective Calculations
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void OGL_Consumer::setLesson(unsigned int lessonNum)
{
	if (lessonNum >= LESSON_QTY)
		return;

	m_lessonNum = lessonNum;
}

bool OGL_Consumer::sendMessage(unsigned int lessonNum, int message, int mode, int x, int y)
{
	return m_lesson[m_lessonNum]->sendMessage(message, mode, x, y);
}

void OGL_Consumer::reshape(unsigned int width, unsigned int height)
{
	m_lesson[m_lessonNum]->reshape(width, height);
}

// Here goes our drawing code
void OGL_Consumer::drawGLScene()
{
	m_lesson[m_lessonNum]->drawGLScene();
}

char* OGL_Consumer::getLessonName()
{
	return m_lesson[m_lessonNum]->getName();
}
