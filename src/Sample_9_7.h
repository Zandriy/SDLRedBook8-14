/*
 * Sample_9_7.h
 *
 *  Created on: Dec 27, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_7_H_
#define Sample_9_7_H_

#include "Sample.h"

#define checkImageWidth 64
#define	 checkImageHeight 64

class Sample_9_7 : public Sample
{
public:
	Sample_9_7();
	virtual ~Sample_9_7();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-7. Texbind";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_checkImage[checkImageHeight][checkImageWidth][4];
	GLubyte m_otherImage[checkImageHeight][checkImageWidth][4];
	bool m_imageCreated;
	GLuint m_texName[2];

	void makeCheckImage();
};

#endif /* Sample_9_7_H_ */
