/*
 * Sample_9_4.h
 *
 *  Created on: Dec 24, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_4_H_
#define Sample_9_4_H_

#include "Sample.h"

#define iwidth 16
#define iheight 16
#define idepth 16

class Sample_9_4 : public Sample
{
public:
	Sample_9_4();
	virtual ~Sample_9_4();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-4. Texture3d(d-D,s-S)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_image[idepth][iheight][iwidth][3];
	bool m_imageCreated;
	GLuint m_texName;
	GLfloat m_deep;

	void makeImage();
};

#endif /* Sample_9_4_H_ */
