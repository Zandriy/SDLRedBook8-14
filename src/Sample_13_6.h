/*
 * Sample_13_6.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_13_6_H_
#define SAMPLE_13_6_H_

#include "Sample.h"

class Sample_13_6: public Sample {
public:
	Sample_13_6();
	virtual ~Sample_13_6();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"13-6. PickDepth(mouse)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

	void drawRects(GLenum mode);
	void processHits (GLint hits, GLuint buffer[]);
};

#endif /* SAMPLE_13_6_H_ */
