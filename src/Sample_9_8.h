/*
 * Sample_9_8.h
 *
 *  Created on: Jan 3, 2013
 *      Author: Andrew Zhabura
 */

#ifndef Sample_9_8_H_
#define Sample_9_8_H_

#include "Sample.h"

#define	stripeImageWidth 32

class Sample_9_8 : public Sample
{
public:
	Sample_9_8();
	virtual ~Sample_9_8();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"9-8. Texgen(e-E,o-O,s-S,x-X)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLubyte m_stripeImage[4*stripeImageWidth];
	bool m_imageCreated;
	GLuint m_texName;;
	GLfloat *m_currentCoeff;
	GLenum m_currentPlane;
	GLint m_currentGenMode;

	void makeStripeImage();
};

#endif /* Sample_9_8_H_ */
