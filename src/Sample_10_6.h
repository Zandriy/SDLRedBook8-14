/*
 * Sample_10_6.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_10_6_H_
#define SAMPLE_10_6_H_

#include "Sample.h"

class Sample_10_6: public Sample {
public:
	Sample_10_6();
	virtual ~Sample_10_6();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"10-6. Dof(b-B)";
	}

	bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLuint m_sphereList;
	void renderSphere (GLfloat x, GLfloat y, GLfloat z,
	   GLfloat ambr, GLfloat ambg, GLfloat ambb,
	   GLfloat difr, GLfloat difg, GLfloat difb,
	   GLfloat specr, GLfloat specg, GLfloat specb, GLfloat shine);
};

#endif /* SAMPLE_10_6_H_ */
