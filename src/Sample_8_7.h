/*
 * Sample_8_7.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_7_H_
#define Sample_8_7_H_

#include "Sample.h"
#include "OGLImageRec.h"

class Sample_8_7 : public Sample
{
public:
	Sample_8_7();
	virtual ~Sample_8_7();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-7. Color Table(1-2-3,r-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	OGLImageRec	m_image;
	bool m_reversing, m_prevReversing;

	void setColorMatrix();
};

#endif /* Sample_8_7_H_ */
