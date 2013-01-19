/*
 * Sample_11_4.h
 *
 *  Created on: Jan 19, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_11_4_H_
#define SAMPLE_11_4_H_

#include "Sample.h"

class Sample_11_4: public Sample {
public:
	Sample_11_4();
	virtual ~Sample_11_4();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"11-4. Quadric";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLUquadricObj *m_qobj;
	GLuint m_startList;
};

#endif /* SAMPLE_11_4_H_ */
