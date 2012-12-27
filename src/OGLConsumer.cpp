/*
 * OGLConsumer.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: Andrew Zhabura
 */

#include <exception>

#include "OGLConsumer.h"

#include "Sample_8_1.h"
#include "Sample_8_2.h"
#include "Sample_8_4.h"
#include "Sample_8_5.h"
#include "Sample_8_6.h"
#include "Sample_8_7.h"
#include "Sample_8_8.h"
#include "Sample_8_9.h"
#include "Sample_8_10.h"
#include "Sample_9_1.h"
#include "Sample_9_3.h"
#include "Sample_9_4.h"
#include "Sample_9_5.h"
#include "Sample_9_7.h"

#define Sample_QTY 14

OGL_Consumer::OGL_Consumer()
:	m_Sample(new Sample * [Sample_QTY])
,	m_SampleNum(0)
{
	int i = -1;

	m_Sample[++i] = new Sample_8_1;
	m_Sample[++i] = new Sample_8_2;
	m_Sample[++i] = new Sample_8_4;
	m_Sample[++i] = new Sample_8_5;
	m_Sample[++i] = new Sample_8_6;
	m_Sample[++i] = new Sample_8_7;
	m_Sample[++i] = new Sample_8_8;
	m_Sample[++i] = new Sample_8_9;
	m_Sample[++i] = new Sample_8_10;
	m_Sample[++i] = new Sample_9_1;
	m_Sample[++i] = new Sample_9_3;
	m_Sample[++i] = new Sample_9_4;
	m_Sample[++i] = new Sample_9_5;
	m_Sample[++i] = new Sample_9_7;

	if ( ++i != Sample_QTY )
		throw this;
}

OGL_Consumer::~OGL_Consumer()
{
	for (int i = 0; i < Sample_QTY; ++i)
	{
		if (m_Sample[i])
			delete m_Sample[i];
	}
}

void OGL_Consumer::setSample(unsigned int SampleNum)
{
	if (SampleNum >= Sample_QTY)
		return;

	m_SampleNum = SampleNum;
}

bool OGL_Consumer::sendMessage(unsigned int SampleNum, int message, int mode, int x, int y)
{
	return m_Sample[m_SampleNum]->sendMessage(message, mode, x, y);
}

void OGL_Consumer::reshape(unsigned int width, unsigned int height)
{
	m_Sample[m_SampleNum]->reshape(width, height);
}

// Here goes our drawing code
void OGL_Consumer::drawGLScene()
{
	m_Sample[m_SampleNum]->drawGLScene();
}

char* OGL_Consumer::getSampleName()
{
	return m_Sample[m_SampleNum]->getName();
}
