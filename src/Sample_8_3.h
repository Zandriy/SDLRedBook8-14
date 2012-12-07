/*
 * Sample_8_3.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_3_H_
#define Sample_8_3_H_

#include "Sample.h"

class Sample_8_3 : public Sample
{
public:
	Sample_8_3();
	virtual ~Sample_8_3();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-3. Image(r-R,z-Z)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte *m_checkImage;
	GLdouble m_zoomFactor;
	GLint m_height;

	void makeCheckImage();
	void motion(int x, int y);
};

#endif /* Sample_8_3_H_ */
