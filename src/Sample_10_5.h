/*
 * Sample_10_5.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_10_5_H_
#define SAMPLE_10_5_H_

#include "Sample.h"

class Sample_10_5: public Sample {
public:
	Sample_10_5();
	virtual ~Sample_10_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"10-5. Motiblur";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	void displayObjects(GLfloat xoffset,GLfloat yrot);
};

#endif /* SAMPLE_10_5_H_ */
