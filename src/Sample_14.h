/*
 * Sample_14.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#ifndef Sample_14_H_
#define Sample_14_H_

#include "Sample.h"

class Sample_14 : public Sample
{
	typedef struct charpoint {
		GLfloat   x, y;
		int    type;
	} CP;

	enum {
		PT,
		STROKE,
		END
	};

public:
	Sample_14();
	virtual ~Sample_14();

	virtual void reshape(int width, int height);
	virtual char* getName()
	{
		return (char*)&"14. Info(p-P)";
	}

	virtual bool sendMessage(int message, int mode, int x, int y);

protected:
	virtual void draw();
	virtual void initGL();
	virtual void restoreGL();

private:
	void createLetters();
	void drawLetter(CP *l);
	void printStrokedString(const char *s);

	GLuint m_base;

	static CP m_0data[];
	static CP m_1data[];
	static CP m_2data[];
	static CP m_3data[];
	static CP m_4data[];
	static CP m_5data[];
	static CP m_6data[];
	static CP m_7data[];
	static CP m_8data[];
	static CP m_9data[];

	static CP m_point_data[];
	static CP m_comma_data[];
	static CP m_dash_data[];
	static CP m_quest_data[];
	static CP m_underscore_data[];
	static CP m_leftRoundBracket_data[];
	static CP m_rightRoundBracket_data[];
	static CP m_rightLine_data[];
	static CP m_vertLine_data[];

	static CP m_Adata[];
	static CP m_Bdata[];
	static CP m_Cdata[];
	static CP m_Ddata[];
	static CP m_Edata[];
	static CP m_Fdata[];
	static CP m_Gdata[];
	static CP m_Hdata[];
	static CP m_Idata[];
	static CP m_Jdata[];
	static CP m_Kdata[];
	static CP m_Ldata[];
	static CP m_Mdata[];
	static CP m_Ndata[];
	static CP m_Odata[];
	static CP m_Pdata[];
	static CP m_Qdata[];
	static CP m_Rdata[];
	static CP m_Sdata[];
	static CP m_Tdata[];
	static CP m_Udata[];
	static CP m_Vdata[];
	static CP m_Wdata[];
	static CP m_Xdata[];
	static CP m_Ydata[];
	static CP m_Zdata[];

	static char* test;
	static char* alphabet;
	static char* numbers;
	static char* signs;

	GLdouble	m_x;
	GLdouble	m_y;
};

#endif /* Sample_14_H_ */
