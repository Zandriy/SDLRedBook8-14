/*
 * Sample_9_3.h
 *
 *  Created on: Dec 24, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_3_H_
#define Sample_9_3_H_

#include "Sample.h"

#define checkImageWidth 64
#define	 checkImageHeight 64
#define subImageWidth 16
#define subImageHeight 16

class Sample_9_3 : public Sample
{
public:
	Sample_9_3();
	virtual ~Sample_9_3();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-3. Texsub(s-S,r-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_checkImage[checkImageHeight][checkImageWidth][4];
	GLubyte m_subImage[subImageHeight][subImageWidth][4];
	bool m_imageCreated;
	bool m_drawSub;
	GLuint m_texName;

	void makeCheckImage();
};

#endif /* Sample_9_3_H_ */
