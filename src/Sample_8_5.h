/*
 * Sample_8_5.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_5_H_
#define Sample_8_5_H_

#include "Sample.h"

#define		tableSize	256
#define		rgb			3

#include <cstdlib>
#include <iostream>
#include <fstream>

class OGLImageRec
{
public:
	OGLImageRec()
	:	m_sizeX(0)
	,	m_sizeY(0)
	,	m_data(NULL)
	{
	}

	~OGLImageRec()
	{
		delete [] m_data;
	}

	unsigned int sizeX() { return m_sizeX; }
	unsigned int sizeY() { return m_sizeY; }
	unsigned char* data() { return m_data; }

	// Routine to read a bitmap file.
	// Works only for uncompressed m_bmp files of 24-bit color.
	void loadBMP( std::string filename )
	{
		if (m_data)
		{
			delete [] m_data;
			m_data = NULL;
		}

		unsigned int size, offset, headerSize;

		// Read input file name.
		std::ifstream infile(filename.c_str(), std::ios::binary);

		// Get the starting point of the image data.
		infile.seekg(10);
		infile.read((char *) &offset, 4);

		// Get the header size of the bitmap.
		infile.read((char *) &headerSize,4);

		// Get width and height values in the bitmap header.
		infile.seekg(18);
		infile.read( (char *) &m_sizeX, 4);
		infile.read( (char *) &m_sizeY, 4);

		// Allocate buffer for the image.
		size = m_sizeX * m_sizeY * 24;
		m_data = new unsigned char[size];

		// Read bitmap data.
		infile.seekg(offset);
		infile.read((char *) m_data , size);

		// Reverse color from bgr to rgb.
		int temp;
		for (int i = 0; i < size; i += 3)
		{
			temp = m_data[i];
			m_data[i] = m_data[i+2];
			m_data[i+2] = temp;
		}
	}

private:
	unsigned int m_sizeX;
	unsigned int m_sizeY;
	unsigned char *m_data;
};

class Sample_8_5 : public Sample
{
public:
	Sample_8_5();
	virtual ~Sample_8_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-5. Colortable(1-2,o-O,i-I,r-R,g-G,b-B)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	enum TableType_t {
		NONE,
		INVERT,
		RED_CHANNEL,
		GREEN_CHANNEL,
		BLUE_CHANNEL
	};

	GLubyte m_clrTable[tableSize][rgb];
	OGLImageRec	m_image;
	TableType_t	m_prevTblType;
	TableType_t	m_tblType;

	void createClrTable();
};

#endif /* Sample_8_5_H_ */
