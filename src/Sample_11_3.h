/*
 * Sample_11_3.h
 *
 *  Created on: Jan 17, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_11_3_H_
#define SAMPLE_11_3_H_

#include "Sample.h"

class Sample_11_3: public Sample {
public:
	Sample_11_3();
	virtual ~Sample_11_3();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"11-3. Tess";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	GLUtesselator *m_tobj;
	GLuint m_startList;
};

#endif /* SAMPLE_11_3_H_ */
