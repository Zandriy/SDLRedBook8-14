/*
 * Sample_8_5.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_5_H_
#define Sample_8_5_H_

#include "Sample.h"

#define		checkImageWidth		64
#define		checkImageHeight	64
#define		checkImageColors	3

class Sample_8_5 : public Sample
{
public:
	Sample_8_5();
	virtual ~Sample_8_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-5. Colortable";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_checkImage[checkImageWidth][checkImageHeight][checkImageColors];
	GLdouble m_zoomFactor;
	GLint m_height;
	bool m_bImageCreated;
	bool m_bMotion;
	int m_X;
	int m_Y;

	void makeCheckImage();
	void motion(int x, int y);
};

#endif /* Sample_8_5_H_ */
