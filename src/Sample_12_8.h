/*
 * Sample_12_8.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_8_H_
#define SAMPLE_12_8_H_

#include "Sample.h"

class Sample_12_8: public Sample {
public:
	Sample_12_8();
	virtual ~Sample_12_8();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-5. Trim(c-C)";
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

#endif /* SAMPLE_12_8_H_ */
