/*
 * Sample_12_2.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_2_H_
#define SAMPLE_12_2_H_

#include "Sample.h"

class Sample_12_2: public Sample {
public:
	Sample_12_2();
	virtual ~Sample_12_2();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-2. BezSurf";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();
};

#endif /* SAMPLE_12_2_H_ */
