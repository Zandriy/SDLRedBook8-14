/*
 * Sample_8_9.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_9_H_
#define Sample_8_9_H_

#include "Sample.h"
#include "OGLImageRec.h"

#define	 HISTOGRAM_SIZE	256

class Sample_8_9 : public Sample
{
public:
	Sample_8_9();
	virtual ~Sample_8_9();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-9. MinMax(=1,=2,=3)";
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
	GLushort values[HISTOGRAM_SIZE][3];
};

#endif /* Sample_8_9_H_ */
