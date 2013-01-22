/*
 * Sample_13_7.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_13_7_H_
#define SAMPLE_13_7_H_

#include "Sample.h"

class Sample_13_7: public Sample {
public:
	Sample_13_7();
	virtual ~Sample_13_7();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"13-7. Feedback";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

	void drawGeometry (GLenum mode);
	void printBuffer(GLint size, GLfloat *buffer);
	void print3DcolorVertex (GLint size, GLint *count,
	                         GLfloat *buffer);
};

#endif /* SAMPLE_13_7_H_ */
