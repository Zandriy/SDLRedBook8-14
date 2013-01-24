/*
 * Sample_12_4.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_4_H_
#define SAMPLE_12_4_H_

#include "Sample.h"

class Sample_12_4: public Sample {
public:
	Sample_12_4();
	virtual ~Sample_12_4();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-4. TextureSurf";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	void initlights();
};

#endif /* SAMPLE_12_4_H_ */
