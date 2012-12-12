/*
 * Sample_8_6.h
 *
 *  Created on: Dec 7, 2012
 *      Author: Andrew Zhabura
 */

#ifndef Sample_8_6_H_
#define Sample_8_6_H_

#include "Sample.h"
#include "OGLImageRec.h"

class Sample_8_6 : public Sample
{
public:
	Sample_8_6();
	virtual ~Sample_8_6();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"8-6. Convolution(1-2-3,o-O,h-H,v-V,l-L)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	void draw();
	void initGL();
	void restoreGL();

private:
	enum FilterType_t {
		NONE,
		HORISONTAL,
		VERTICAL,
		LAPLACIAN
	};

	OGLImageRec	m_image;
	FilterType_t	m_fltrType;

	void setFilter();
};

#endif /* Sample_8_6_H_ */
