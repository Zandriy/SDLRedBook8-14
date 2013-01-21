/*
 * Sample_12_5.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_5_H_
#define SAMPLE_12_5_H_

#include "Sample.h"

class Sample_12_5: public Sample {
public:
	Sample_12_5();
	virtual ~Sample_12_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-5. Surface(c-C)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLfloat m_ctlpoints[4][4][3];
	bool m_showPoints;
	GLUnurbsObj *m_theNurb;
};

#endif /* SAMPLE_12_5_H_ */
