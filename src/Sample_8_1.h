/*
 * Sample_8_1.h
 *
 *  Created on: Dec 6, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_1_H_
#define Sample_8_1_H_

#include "Sample.h"

class Sample_8_1 : public Sample
{
public:
	Sample_8_1();
	virtual ~Sample_8_1();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-1. DrawF";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();
};

#endif /* Sample_8_1_H_ */
