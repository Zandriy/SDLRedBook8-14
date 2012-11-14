/*
 * Lesson_6_0.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_6_0_H_
#define LESSON_6_0_H_

#include "Lesson.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Lesson_6_0 : public Lesson
{
	// Structure of bitmap file.
	struct BitMapFile
	{
	   int sizeX;
	   int sizeY;
	   unsigned char *data;
	};

public:
	Lesson_6_0();
	virtual ~Lesson_6_0();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"6-0. Billboarding (mouse L-R)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);
private:
	void draw();

	void getBMPData(std::string filename);
	void loadExternalTextures();

	BitMapFile *m_bmp;
	unsigned int m_texture;
	unsigned int m_seg;
	float m_angle;
};

#endif /* LESSON_6_0_H_ */
