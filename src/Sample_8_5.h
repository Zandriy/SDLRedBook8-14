/*
 * Sample_8_5.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_5_H_
#define Sample_8_5_H_

#include "Sample.h"
#include "OGLImageRec.h"

#define		tableSize	256
#define		rgb			3

class Sample_8_5 : public Sample
{
public:
	Sample_8_5();
	virtual ~Sample_8_5();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-5. Colortable(1-2-3,o-O,i-I,r-R,g-G,b-B)";
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
