/*
 * Sample_14.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_14.h"
#include "OGLInspector.h"

#include <string>
#include <SDL/SDL.h>

////// NUMBERS

Sample_14::CP Sample_14::m_0data[] = {
		{5, 9, PT}, {5, 1, PT}, {4, 0, PT},
		{1, 0, PT}, {0, 1, PT}, {0, 9, PT},
		{1, 10, PT}, {4, 10, PT}, {5, 9, STROKE},
		{0, 2, PT}, {5, 8, END}
};

Sample_14::CP Sample_14::m_1data[] = {
		{3, 0, PT}, {3, 10, STROKE},
		{1, 0, PT}, {5, 0, STROKE},
		{1, 7, PT}, {3, 10, END}
};

Sample_14::CP Sample_14::m_2data[] = {
		{0, 7, PT}, {0, 9, PT}, {1, 10, PT}, {4, 10, PT},
		{5, 9, PT}, {5, 7, PT}, {0, 0, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_3data[] = {
		{0, 10, PT}, {5, 10, PT}, {2, 6, STROKE},
		{3, 7, PT}, {4, 7, PT}, {5, 6, PT},
		{5, 1, PT}, {4, 0, PT}, {0, 0, END}
};

Sample_14::CP Sample_14::m_4data[] = {
		{3, 10, PT}, {0, 3, PT}, {5, 3, STROKE},
		{4, 0, PT}, {4, 5, END}
};

Sample_14::CP Sample_14::m_5data[] = {
		{5, 10, PT}, {0, 10, PT}, {0, 7, PT},
		{4, 7, PT}, {5, 6, PT}, {5, 1, PT},
		{4, 0, PT}, {0, 0, END}
};

Sample_14::CP Sample_14::m_6data[] = {
		{3, 10, PT}, {0, 6, PT}, {0, 1, PT},
		{1, 0, PT}, {4, 0, PT}, {5, 1, PT},
		{5, 5, PT}, {4, 6, PT}, {0, 6, END}
};

Sample_14::CP Sample_14::m_7data[] = {
		{0, 10, PT}, {5, 10, PT}, {0, 0, END}
};

Sample_14::CP Sample_14::m_8data[] = {
		{1, 6, PT}, {1, 9, PT}, {2, 10, PT}, {3, 10, PT}, {4, 9, PT}, {4, 6, STROKE},
		{1, 6, PT}, {0, 5, PT}, {0, 1, PT},
		{1, 0, PT}, {4, 0, PT}, {5, 1, PT},
		{5, 5, PT}, {4, 6, PT}, {1, 6, END}
};

Sample_14::CP Sample_14::m_9data[] = {
		{2, 0, PT}, {5, 4, PT}, {5, 9, PT},
		{4, 10, PT}, {1, 10, PT}, {0, 9, PT},
		{0, 5, PT}, {1, 4, PT}, {5, 4, END}
};

////// SIGNS

Sample_14::CP Sample_14::m_point_data[] = {
		{3, 0, PT}, {4, 0, PT},
		{4, 1, PT}, {3, 1, PT}, {3, 0, END}
};

Sample_14::CP Sample_14::m_comma_data[] = {
		{4, 0, PT}, {3, 0, PT}, {3, 1, PT},
		{4, 1, PT}, {4, 0, PT}, {3, -1, END}
};

Sample_14::CP Sample_14::m_dash_data[] = {
		{0, 5, PT}, {5, 5, END}
};

Sample_14::CP Sample_14::m_quest_data[] = {
		{0, 7, PT}, {0, 9, PT}, {1, 10, PT}, {4, 10, PT},
		{5, 9, PT}, {5, 7, PT}, {2, 3, STROKE},
		{2, 1, PT},  {2, 0, END}
};

Sample_14::CP Sample_14::m_underscore_data[] = {
		{0, 0, PT},  {5, 0, END}
};

Sample_14::CP Sample_14::m_leftRoundBracket_data[] = {
		{2, 0, PT}, {0, 2, PT}, {0, 8, PT},  {2, 10, END}
};

Sample_14::CP Sample_14::m_rightRoundBracket_data[] = {
		{3, 0, PT}, {5, 2, PT}, {5, 8, PT},  {3, 10, END}
};

Sample_14::CP Sample_14::m_rightLine_data[] = {
		{0, 0, PT},  {5, 10, END}
};

Sample_14::CP Sample_14::m_vertLine_data[] = {
		{3, 0, PT},  {3, 10, END}
};

////// LETTERS

Sample_14::CP Sample_14::m_Adata[] = {
		{ 0, 0, PT}, {0, 9, PT}, {1, 10, PT}, {4, 10, PT},
		{5, 9, PT}, {5, 0, STROKE}, {0, 5, PT}, {5, 5, END}
};

Sample_14::CP Sample_14::m_Bdata[] = {
		{0, 6, PT}, {4, 6, PT}, {5, 5, PT}, {5, 1, PT},
		{4, 0, PT}, {0, 0, PT}, {0, 10, PT}, {3, 10, PT}, {4, 9, PT}, {4, 6, END}
};

Sample_14::CP Sample_14::m_Cdata[] = {
		{5, 0, PT}, {1, 0, PT}, {0, 1, PT}, {0, 9, PT}, {1, 10, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Ddata[] = {
		{4, 0, PT}, {0, 0, PT}, {0, 10, PT}, {4, 10, PT},
		{5, 9, PT}, {5, 1, PT}, {4, 0, END}
};

Sample_14::CP Sample_14::m_Edata[] = {
		{5, 0, PT}, {0, 0, PT}, {0, 10, PT}, {5, 10, STROKE},
		{0, 5, PT}, {4, 5, END}
};

Sample_14::CP Sample_14::m_Fdata[] = {
		{0, 0, PT}, {0, 10, PT}, {5, 10, STROKE},
		{0, 5, PT}, {4, 5, END}
};

Sample_14::CP Sample_14::m_Gdata[] = {
		{2, 5, PT}, {5, 5, PT}, {5, 0, PT}, {1, 0, PT}, {0, 1, PT},
		{0, 9, PT}, {1, 10, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Hdata[] = {
		{0, 0, PT}, {0, 10, STROKE},
		{5, 0, PT}, {5, 10, STROKE},
		{0, 5, PT}, {5, 5, END}
};

Sample_14::CP Sample_14::m_Idata[] = {
		{3, 0, PT}, {3, 10, STROKE},
		{1, 0, PT}, {5, 0, STROKE},
		{1, 10, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Jdata[] = {
		{2, 10, PT}, {5, 10, PT}, {5, 1, PT},
		{4, 0, PT}, {1, 0, PT}, {0, 1, END}
};

Sample_14::CP Sample_14::m_Kdata[] = {
		{0, 0, PT}, {0, 10, STROKE},  {4, 10, PT}, {0, 4, STROKE},
		{1, 6, PT}, {3, 6, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_Ldata[] = {
		{5, 0, PT}, {0, 0, PT}, {0, 10, END}
};

Sample_14::CP Sample_14::m_Mdata[] = {
		{0, 0, PT}, {0, 10, PT}, {2.5, 5, PT},
		{5, 10, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_Ndata[] = {
		{0, 0, PT}, {0, 10, PT},
		{5, 0, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Odata[] = {
		{5, 9, PT}, {5, 1, PT}, {4, 0, PT},
		{1, 0, PT}, {0, 1, PT}, {0, 9, PT},
		{1, 10, PT}, {4, 10, PT}, {5, 9, END}
};

Sample_14::CP Sample_14::m_Pdata[] = {
		{0, 0, PT}, {0, 10, PT},  {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
		{4, 5, PT}, {0, 5, END}
};

Sample_14::CP Sample_14::m_Qdata[] = {
		{5, 9, PT}, {5, 3, PT}, {3, 0, PT},
		{1, 0, PT}, {0, 1, PT}, {0, 9, PT},
		{1, 10, PT}, {4, 10, PT}, {5, 9, STROKE},
		{3, 3, PT}, {4, 2, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_Rdata[] = {
		{0, 0, PT}, {0, 10, PT},  {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
		{4, 5, PT}, {0, 5, STROKE}, {3, 5, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_Sdata[] = {
		{0, 1, PT}, {1, 0, PT}, {4, 0, PT}, {5, 1, PT}, {5, 4, PT},
		{4, 5, PT}, {1, 5, PT}, {0, 6, PT}, {0, 9, PT}, {1, 10, PT},
		{4, 10, PT}, {5, 9, END}
};

Sample_14::CP Sample_14::m_Tdata[] = {
		{2.5, 0, PT}, {2.5, 10, STROKE},
		{0, 10, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Udata[] = {
		{5, 10, PT}, {5, 1, PT}, {4, 0, PT},
		{1, 0, PT}, {0, 1, PT}, {0, 10, END}
};

Sample_14::CP Sample_14::m_Vdata[] = {
		{5, 10, PT}, {2.5, 0, PT}, {0, 10, END}
};

Sample_14::CP Sample_14::m_Wdata[] = {
		{5, 10, PT}, {4, 0, PT}, {2.5, 5, PT},
		{1, 0, PT}, {0, 10, END}
};

Sample_14::CP Sample_14::m_Xdata[] = {
		{0, 0, PT}, {5, 10, STROKE},
		{0, 10, PT}, {5, 0, END}
};

Sample_14::CP Sample_14::m_Ydata[] = {
		{2.5, 0, PT}, {2.5, 5, STROKE},
		{0, 10, PT}, {2.5, 5, PT}, {5, 10, END}
};

Sample_14::CP Sample_14::m_Zdata[] = {
		{0, 10, PT}, {5, 10, PT}, {0, 0, PT}, {5, 0, END}
};

char* Sample_14::test = (char*)&"THE QUICK BROWN FOX JUMPS OVER A LAZY DOG";
char* Sample_14::alphabet = (char*)&"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* Sample_14::numbers = (char*)&"0123456789";
char* Sample_14::signs = (char*)&".,-_?/|()";

Sample_14::Sample_14()
: m_base(0)
, m_x(0.0)
, m_y(0.0)
{
}

Sample_14::~Sample_14() {
	delete [] test;
	delete [] alphabet;
	delete [] numbers;
	delete [] signs;
}

void Sample_14::reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	m_x = (GLdouble) w;
	m_y = (GLdouble) h;
	gluOrtho2D (0.0, m_x, 0.0, m_y);
}

void Sample_14::createLetters()
{
	// !!! commented because of problems on MAC
	//if (!m_base)
	//{
		m_base = glGenLists (128);
		glListBase(m_base);

		for (GLuint i = 0; i < 128; ++i)
		{
			glNewList(m_base+i, GL_COMPILE); drawLetter(m_quest_data); glEndList();
		}

		glNewList(m_base+'0', GL_COMPILE); drawLetter(m_0data); glEndList();
		glNewList(m_base+'1', GL_COMPILE); drawLetter(m_1data); glEndList();
		glNewList(m_base+'2', GL_COMPILE); drawLetter(m_2data); glEndList();
		glNewList(m_base+'3', GL_COMPILE); drawLetter(m_3data); glEndList();
		glNewList(m_base+'4', GL_COMPILE); drawLetter(m_4data); glEndList();
		glNewList(m_base+'5', GL_COMPILE); drawLetter(m_5data); glEndList();
		glNewList(m_base+'6', GL_COMPILE); drawLetter(m_6data); glEndList();
		glNewList(m_base+'7', GL_COMPILE); drawLetter(m_7data); glEndList();
		glNewList(m_base+'8', GL_COMPILE); drawLetter(m_8data); glEndList();
		glNewList(m_base+'9', GL_COMPILE); drawLetter(m_9data); glEndList();

		glNewList(m_base+'.', GL_COMPILE); drawLetter(m_point_data); glEndList();
		glNewList(m_base+',', GL_COMPILE); drawLetter(m_comma_data); glEndList();
		glNewList(m_base+'-', GL_COMPILE); drawLetter(m_dash_data); glEndList();
		glNewList(m_base+'_', GL_COMPILE); drawLetter(m_underscore_data); glEndList();
		glNewList(m_base+'?', GL_COMPILE); drawLetter(m_quest_data); glEndList();
		glNewList(m_base+'(', GL_COMPILE); drawLetter(m_leftRoundBracket_data); glEndList();
		glNewList(m_base+')', GL_COMPILE); drawLetter(m_rightRoundBracket_data); glEndList();
		glNewList(m_base+'/', GL_COMPILE); drawLetter(m_rightLine_data); glEndList();
		glNewList(m_base+'|', GL_COMPILE); drawLetter(m_vertLine_data); glEndList();

		glNewList(m_base+'A', GL_COMPILE); drawLetter(m_Adata); glEndList();
		glNewList(m_base+'B', GL_COMPILE); drawLetter(m_Bdata); glEndList();
		glNewList(m_base+'C', GL_COMPILE); drawLetter(m_Cdata); glEndList();
		glNewList(m_base+'D', GL_COMPILE); drawLetter(m_Ddata); glEndList();
		glNewList(m_base+'E', GL_COMPILE); drawLetter(m_Edata); glEndList();
		glNewList(m_base+'F', GL_COMPILE); drawLetter(m_Fdata); glEndList();
		glNewList(m_base+'G', GL_COMPILE); drawLetter(m_Gdata); glEndList();
		glNewList(m_base+'H', GL_COMPILE); drawLetter(m_Hdata); glEndList();
		glNewList(m_base+'I', GL_COMPILE); drawLetter(m_Idata); glEndList();
		glNewList(m_base+'J', GL_COMPILE); drawLetter(m_Jdata); glEndList();
		glNewList(m_base+'K', GL_COMPILE); drawLetter(m_Kdata); glEndList();
		glNewList(m_base+'L', GL_COMPILE); drawLetter(m_Ldata); glEndList();
		glNewList(m_base+'M', GL_COMPILE); drawLetter(m_Mdata); glEndList();
		glNewList(m_base+'N', GL_COMPILE); drawLetter(m_Ndata); glEndList();
		glNewList(m_base+'O', GL_COMPILE); drawLetter(m_Odata); glEndList();
		glNewList(m_base+'P', GL_COMPILE); drawLetter(m_Pdata); glEndList();
		glNewList(m_base+'Q', GL_COMPILE); drawLetter(m_Qdata); glEndList();
		glNewList(m_base+'R', GL_COMPILE); drawLetter(m_Rdata); glEndList();
		glNewList(m_base+'S', GL_COMPILE); drawLetter(m_Sdata); glEndList();
		glNewList(m_base+'T', GL_COMPILE); drawLetter(m_Tdata); glEndList();
		glNewList(m_base+'U', GL_COMPILE); drawLetter(m_Udata); glEndList();
		glNewList(m_base+'V', GL_COMPILE); drawLetter(m_Vdata); glEndList();
		glNewList(m_base+'W', GL_COMPILE); drawLetter(m_Wdata); glEndList();
		glNewList(m_base+'X', GL_COMPILE); drawLetter(m_Xdata); glEndList();
		glNewList(m_base+'Y', GL_COMPILE); drawLetter(m_Ydata); glEndList();
		glNewList(m_base+'Z', GL_COMPILE); drawLetter(m_Zdata); glEndList();

		glNewList(m_base+'a', GL_COMPILE); drawLetter(m_Adata); glEndList();
		glNewList(m_base+'b', GL_COMPILE); drawLetter(m_Bdata); glEndList();
		glNewList(m_base+'c', GL_COMPILE); drawLetter(m_Cdata); glEndList();
		glNewList(m_base+'d', GL_COMPILE); drawLetter(m_Ddata); glEndList();
		glNewList(m_base+'e', GL_COMPILE); drawLetter(m_Edata); glEndList();
		glNewList(m_base+'f', GL_COMPILE); drawLetter(m_Fdata); glEndList();
		glNewList(m_base+'g', GL_COMPILE); drawLetter(m_Gdata); glEndList();
		glNewList(m_base+'h', GL_COMPILE); drawLetter(m_Hdata); glEndList();
		glNewList(m_base+'i', GL_COMPILE); drawLetter(m_Idata); glEndList();
		glNewList(m_base+'j', GL_COMPILE); drawLetter(m_Jdata); glEndList();
		glNewList(m_base+'k', GL_COMPILE); drawLetter(m_Kdata); glEndList();
		glNewList(m_base+'l', GL_COMPILE); drawLetter(m_Ldata); glEndList();
		glNewList(m_base+'m', GL_COMPILE); drawLetter(m_Mdata); glEndList();
		glNewList(m_base+'n', GL_COMPILE); drawLetter(m_Ndata); glEndList();
		glNewList(m_base+'o', GL_COMPILE); drawLetter(m_Odata); glEndList();
		glNewList(m_base+'p', GL_COMPILE); drawLetter(m_Pdata); glEndList();
		glNewList(m_base+'q', GL_COMPILE); drawLetter(m_Qdata); glEndList();
		glNewList(m_base+'r', GL_COMPILE); drawLetter(m_Rdata); glEndList();
		glNewList(m_base+'s', GL_COMPILE); drawLetter(m_Sdata); glEndList();
		glNewList(m_base+'t', GL_COMPILE); drawLetter(m_Tdata); glEndList();
		glNewList(m_base+'u', GL_COMPILE); drawLetter(m_Udata); glEndList();
		glNewList(m_base+'v', GL_COMPILE); drawLetter(m_Vdata); glEndList();
		glNewList(m_base+'w', GL_COMPILE); drawLetter(m_Wdata); glEndList();
		glNewList(m_base+'x', GL_COMPILE); drawLetter(m_Xdata); glEndList();
		glNewList(m_base+'y', GL_COMPILE); drawLetter(m_Ydata); glEndList();
		glNewList(m_base+'z', GL_COMPILE); drawLetter(m_Zdata); glEndList();

		glNewList(m_base+' ', GL_COMPILE); glTranslatef(8.0, 0.0, 0.0); glEndList();
	//}
	//else
	//	glListBase(m_base); // must be reset to prevent shifting
}

void Sample_14::draw()
{
	createLetters();

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
	glTranslatef(5.0, 35.0, 0.0);
	printStrokedString(numbers);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(85.0, 35.0, 0.0);
	printStrokedString(signs);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(180.0, 35.0, 0.0);
	printStrokedString(alphabet);
	glPopMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(10.0, 20.0, 0.0);
	printStrokedString(test);
	glPopMatrix();

	GLfloat yStart = m_y;
	const GLfloat lineH = 15.0;

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("Last Error");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetLastError().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("Vendor");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetVendor().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("Renderer");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetRenderer().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("GL Version");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetVersion().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("GL Soft Version");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetSoftVersion().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("GLU Version");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetGluVersion().c_str());
	glPopMatrix();

	yStart -= lineH;
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("GL Extensions");
	glPopMatrix();

	std::string str = OGLInspector::GetExtensions();
	int startPos = 0;
	int p = 0;
	int dist = 130;
	while ( startPos != str.length() )
	{
		if (startPos + dist > str.length()-1)
			p = str.length() - startPos - 1;
		else
			p = str.substr(startPos, dist).rfind(" ");

		glPushMatrix();
		glTranslatef(140.0, yStart, 0.0);
		printStrokedString("| ");
		printStrokedString(str.substr(startPos, p).c_str());
		glPopMatrix();

		startPos += (p + 1);
		yStart -= lineH;
	}

	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(5.0, yStart, 0.0);
	printStrokedString("GLU Extensions");
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140.0, yStart, 0.0);
	printStrokedString("| ");
	printStrokedString(OGLInspector::GetGluExtensions().c_str());
	glPopMatrix();
}

void Sample_14::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glShadeModel(GL_FLAT);
}

void Sample_14::restoreGL()
{
	glPopAttrib();
}

/*  drawLetter() interprets the instructions from the array
 *  for that letter and renders the letter with line segments.
 */
void Sample_14::drawLetter(CP *l)
{
	glBegin(GL_LINE_STRIP);
	while (1) {
		switch (l->type) {
		case PT:
			glVertex2fv(&l->x);
			break;
		case STROKE:
			glVertex2fv(&l->x);
			glEnd();
			glBegin(GL_LINE_STRIP);
			break;
		case END:
			glVertex2fv(&l->x);
			glEnd();
			glTranslatef(8.0, 0.0, 0.0);
			return;
		}
		l++;
	}
}

void Sample_14::printStrokedString(const char *s)
{
	GLsizei len = strlen(s);
	glCallLists(len, GL_BYTE, (GLbyte *)s);
}


bool Sample_14::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_p:
		OGLInspector::BuffersReport();
		break;
	default:
		return false;
		break;
	}

	return true;
}
