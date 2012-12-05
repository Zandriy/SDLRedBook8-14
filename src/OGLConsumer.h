/*
 * OGLConsumer.h
 *
 *  Created on: Oct 1, 2012
 *      Author: Andrew Zhabura
 */

#ifndef OGL_CONSUMER_H_
#define OGL_CONSUMER_H_

class Sample;

class OGL_Consumer
{
public:
	OGL_Consumer();
	~OGL_Consumer();
	void setSample(unsigned int SampleNum);
	bool sendMessage(unsigned int SampleNum, int message, int mode, int x, int y);
	void reshape(unsigned int width, unsigned int height);
	void drawGLScene();
	char* getSampleName();

private:
	Sample ** m_Sample;
	unsigned int m_SampleNum;
};

#endif // OGL_CONSUMER_H_
