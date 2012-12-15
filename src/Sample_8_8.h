/*
 * Sample_8_8.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_8_H_
#define Sample_8_8_H_

#include "Sample.h"
#include "OGLImageRec.h"

class Sample_8_8 : public Sample
{
public:
	Sample_8_8();
	virtual ~Sample_8_8();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-8. Histogram(=1,=2,=3,s-S)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	OGLImageRec	m_image;
	bool m_bImagSprt;
	bool m_bLoad;
	GLboolean	m_sink;
	GLboolean	m_prevSink;
};

#endif /* Sample_8_8_H_ */
