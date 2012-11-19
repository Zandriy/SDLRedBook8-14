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
#include "Lesson_3_1.h"
#include "Lesson_3_2.h"
#include "Lesson_3_5.h"
#include "Lesson_3_6.h"
#include "Lesson_3_7.h"
#include "Lesson_3_8.h"
#include "Lesson_4_1.h"
#include "Lesson_5_1.h"
#include "Lesson_5_6.h"
#include "Lesson_5_7.h"
#include "Lesson_5_8.h"
#include "Lesson_5_9.h"
#include "Lesson_5_10.h"
#include "Lesson_6_0.h"
#include "Lesson_6_1.h"
#include "Lesson_6_2.h"
#include "Lesson_6_3.h"
#include "Lesson_6_poly.h"
#include "Lesson_6_5.h"
#include "Lesson_6_7.h"
#include "Lesson_7_1.h"
#include "Lesson_7_2.h"
#include "Lesson_7_5.h"
#include "Lesson_7_7.h"

#define LESSON_QTY 35

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
	m_lesson[11] = new Lesson_3_1;
	m_lesson[12] = new Lesson_3_2;
	m_lesson[13] = new Lesson_3_5;
	m_lesson[14] = new Lesson_3_6;
	m_lesson[15] = new Lesson_3_7;
	m_lesson[16] = new Lesson_3_8;
	m_lesson[17] = new Lesson_4_1;
	m_lesson[18] = new Lesson_5_1;
	m_lesson[19] = new Lesson_5_6;
	m_lesson[20] = new Lesson_5_7;
	m_lesson[21] = new Lesson_5_8;
	m_lesson[22] = new Lesson_5_9;
	m_lesson[23] = new Lesson_5_10;
	m_lesson[24] = new Lesson_6_0;
	m_lesson[25] = new Lesson_6_1;
	m_lesson[26] = new Lesson_6_2;
	m_lesson[27] = new Lesson_6_3;
	m_lesson[28] = new Lesson_6_poly;
	m_lesson[29] = new Lesson_6_5;
	m_lesson[30] = new Lesson_6_7;
	m_lesson[31] = new Lesson_7_1;
	m_lesson[32] = new Lesson_7_2;
	m_lesson[33] = new Lesson_7_5;
	m_lesson[34] = new Lesson_7_7;
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
