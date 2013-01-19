/*
 * Sample_12_1.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_1_H_
#define SAMPLE_12_1_H_

#include "Sample.h"

class Sample_12_1: public Sample {
public:
	Sample_12_1();
	virtual ~Sample_12_1();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-1. BezCurve";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	const GLfloat ctrlpoints[4][3] = {
			{ -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
			{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};
};

#endif /* SAMPLE_12_1_H_ */
