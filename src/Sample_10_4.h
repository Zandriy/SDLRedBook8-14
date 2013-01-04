/*
 * Sample_10_4.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_10_4_H_
#define SAMPLE_10_4_H_

#include "Sample.h"

class Sample_10_4: public Sample {
public:
	Sample_10_4();
	virtual ~Sample_10_4();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"10-4. AccAnti(a-A,n-N)";
	}

	bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	void displayObjects();
	int m_accDraw;
};

#endif /* SAMPLE_10_4_H_ */
