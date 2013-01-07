/*
 * Sample_10_1.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_10_1_H_
#define SAMPLE_10_1_H_

#include "Sample.h"

class Sample_10_1: public Sample {
public:
	Sample_10_1();
	virtual ~Sample_10_1();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"10-1. Stencil";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();
};

#endif /* SAMPLE_10_1_H_ */
