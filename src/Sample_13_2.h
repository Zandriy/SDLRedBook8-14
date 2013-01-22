/*
 * Sample_13_2.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_13_2_H_
#define SAMPLE_13_2_H_

#include "Sample.h"

class Sample_13_2: public Sample {
public:
	Sample_13_2();
	virtual ~Sample_13_2();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"13-2. Select";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

	void drawViewVolume (GLfloat x1, GLfloat x2, GLfloat y1,
			GLfloat y2, GLfloat z1, GLfloat z2);
	void drawTriangle (GLfloat x1, GLfloat y1, GLfloat x2,
			GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z);
	void processHits (GLint hits, GLuint buffer[]);
	void drawScene();
	void selectObjects();
};

#endif /* SAMPLE_13_2_H_ */
