/*
 * Sample_8_10.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_10_H_
#define Sample_8_10_H_

#include "Sample.h"

class Sample_8_10 : public Sample
{
public:
	Sample_8_10();
	virtual ~Sample_8_10();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-10. BlendEquation(a-A,s-S,r-R,m-M,x-X)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();
};

#endif /* Sample_8_10_H_ */
