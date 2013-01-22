/*
 * Sample_13_3.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#ifndef SAMPLE_13_3_H_
#define SAMPLE_13_3_H_

#include "Sample.h"

class Sample_13_3: public Sample {
public:
	Sample_13_3();
	virtual ~Sample_13_3();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"13-3. PickSquare(mouse)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

	int m_board[3][3];   /*  amount of color for each square	*/

	void drawSquares(GLenum mode);
	void processHits (GLint hits, GLuint buffer[]);
	void pickSquares(int button, int state, int x, int y);
};

#endif /* SAMPLE_13_3_H_ */
