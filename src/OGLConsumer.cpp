/*
 * OGLConsumer.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: Andrew Zhabura
 */

#include "OGLConsumer.h"

#include "Lesson_1_2.h"
#include "Lesson_1_3.h"
#include "Lesson_2_5.h"
#include "Lesson_2_6.h"
#include "Lesson_2_7.h"
#include "Lesson_2_9.h"
#include "Lesson_2_10.h"
#include "Lesson_2_11.h"
#include "Lesson_2_13.h"
#include "Lesson_2_15.h"
#include "Lesson_2_15ex.h"

#define LESSON_QTY 11

OGL_Consumer::OGL_Consumer()
:	m_lesson(new Lesson * [LESSON_QTY])
,	m_lessonNum(0)
{
	m_lesson[0] = new Lesson_1_2;
	m_lesson[1] = new Lesson_1_3;
	m_lesson[2] = new Lesson_2_5;
	m_lesson[3] = new Lesson_2_6;
	m_lesson[4] = new Lesson_2_7;
	m_lesson[5] = new Lesson_2_9;
	m_lesson[6] = new Lesson_2_10;
	m_lesson[7] = new Lesson_2_11;
	m_lesson[8] = new Lesson_2_13;
	m_lesson[9] = new Lesson_2_15;
	m_lesson[10] = new Lesson_2_15ex;
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
	glClearColor( 0.1f, 0.1f, 0.3f, 0.0f );

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

void OGL_Consumer::reshape(unsigned int width, unsigned int height)
{
	m_lesson[m_lessonNum]->reshape(width, height);
}

// Here goes our drawing code
void OGL_Consumer::drawGLScene()
{
	m_lesson[m_lessonNum]->drawGLScene();
}

