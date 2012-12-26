/*
 * Sample_9_5.h
 *
 *  Created on: Dec 26, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_5_H_
#define Sample_9_5_H_

#include "Sample.h"

#define iwidth 16
#define iheight 16
#define idepth 16

class Sample_9_5 : public Sample
{
public:
	Sample_9_5();
	virtual ~Sample_9_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-5. Mipmap";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	enum {
		SZ_RGBA = 4,
		SZ_LVL0	= 32,
		SZ_LVL1	= 16,
		SZ_LVL2	= 8,
		SZ_LVL3	= 4,
		SZ_LVL4	= 2,
		SZ_LVL5	= 1
	};

	GLubyte mipmapImage32[SZ_LVL0][SZ_LVL0][SZ_RGBA];
	GLubyte mipmapImage16[SZ_LVL1][SZ_LVL1][SZ_RGBA];
	GLubyte mipmapImage8[SZ_LVL2][SZ_LVL2][SZ_RGBA];
	GLubyte mipmapImage4[SZ_LVL3][SZ_LVL3][SZ_RGBA];
	GLubyte mipmapImage2[SZ_LVL4][SZ_LVL4][SZ_RGBA];
	GLubyte mipmapImage1[SZ_LVL5][SZ_LVL5][SZ_RGBA];
	bool m_imageCreated;
	GLuint m_texName;

	void makeImages();
};

#endif /* Sample_9_5_H_ */
