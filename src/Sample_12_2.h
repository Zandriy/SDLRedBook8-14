/*
 * Sample_12_2.h
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_12_2_H_
#define SAMPLE_12_2_H_

#include "Sample.h"

class Sample_12_2: public Sample {
public:
	Sample_12_2();
	virtual ~Sample_12_2();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"12-2. BezSurf";
	}

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	const GLfloat ctrlpoints[4][4][3] = {
			{{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0}
			, {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}}
			, {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0}
			, {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}}
			, {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0}
			, {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}}
			, {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0}
			, {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
	};
};

#endif /* SAMPLE_12_2_H_ */
