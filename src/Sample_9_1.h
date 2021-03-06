/*
 * Sample_9_1.h
 *
 *  Created on: Dec 23, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_1_H_
#define Sample_9_1_H_

#include "Sample.h"

#define checkImageWidth 64
#define	 checkImageHeight 64

class Sample_9_1 : public Sample
{
public:
	Sample_9_1();
	virtual ~Sample_9_1();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-1. Checker(d-D,c-C,s-S)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_checkImage[checkImageHeight][checkImageWidth][4];
	bool m_imageCreated;
	GLuint m_texName;
	int m_texDir;
	bool m_texClamp;
	GLfloat m_texCoord;

	void makeCheckImage();
};

#endif /* Sample_9_1_H_ */
