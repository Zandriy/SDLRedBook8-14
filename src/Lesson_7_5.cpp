/*
 * Lesson_7_5.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_7_5.h"

#include <SDL/SDL.h>

Lesson_7_5::CP Lesson_7_5::m_Adata[] = {
		{ 0, 0, PT}, {0, 9, PT}, {1, 10, PT}, {4, 10, PT},
		{5, 9, PT}, {5, 0, STROKE}, {0, 5, PT}, {5, 5, END}
};

Lesson_7_5::CP Lesson_7_5::m_Edata[] = {
		{5, 0, PT}, {0, 0, PT}, {0, 10, PT}, {5, 10, STROKE},
		{0, 5, PT}, {4, 5, END}
};

Lesson_7_5::CP Lesson_7_5::m_Pdata[] = {
		{0, 0, PT}, {0, 10, PT},  {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
		{4, 5, PT}, {0, 5, END}
};

Lesson_7_5::CP Lesson_7_5::m_Rdata[] = {
		{0, 0, PT}, {0, 10, PT},  {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
		{4, 5, PT}, {0, 5, STROKE}, {3, 5, PT}, {5, 0, END}
};

Lesson_7_5::CP Lesson_7_5::m_Sdata[] = {
		{0, 1, PT}, {1, 0, PT}, {4, 0, PT}, {5, 1, PT}, {5, 4, PT},
		{4, 5, PT}, {1, 5, PT}, {0, 6, PT}, {0, 9, PT}, {1, 10, PT},
		{4, 10, PT}, {5, 9, END}
};

char* Lesson_7_5::test1 = (char*)&"A SPARE SERAPE APPEARS AS";
char* Lesson_7_5::test2 = (char*)&"APES PREPARE RARE PEPPERS";

Lesson_7_5::Lesson_7_5()
: m_base(0)
{
}

Lesson_7_5::~Lesson_7_5() {
	delete [] test1;
	delete [] test2;
}

void Lesson_7_5::reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) width, 0.0, (GLdouble) height);
}

void Lesson_7_5::drawGLScene()
{
	if (!m_base)
	{
		m_base = glGenLists (128);
		glListBase(m_base);
		glNewList(m_base+'A', GL_COMPILE); drawLetter(m_Adata); glEndList();
		glNewList(m_base+'E', GL_COMPILE); drawLetter(m_Edata); glEndList();
		glNewList(m_base+'P', GL_COMPILE); drawLetter(m_Pdata); glEndList();
		glNewList(m_base+'R', GL_COMPILE); drawLetter(m_Rdata); glEndList();
		glNewList(m_base+'S', GL_COMPILE); drawLetter(m_Sdata); glEndList();
		glNewList(m_base+' ', GL_COMPILE); glTranslatef(8.0, 0.0, 0.0); glEndList();
	}
	glShadeModel(GL_FLAT);

	draw();

	glShadeModel(GL_SMOOTH);
}

void Lesson_7_5::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glScalef(2.0, 2.0, 2.0);
	glTranslatef(10.0, 30.0, 0.0);
	printStrokedString(test1);
	glPopMatrix();
	glPushMatrix();
	glScalef(2.0, 2.0, 2.0);
	glTranslatef(10.0, 13.0, 0.0);
	printStrokedString(test2);
	glPopMatrix();
	glFlush();
}

/*  drawLetter() interprets the instructions from the array
 *  for that letter and renders the letter with line segments.
 */
void Lesson_7_5::drawLetter(CP *l)
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

void Lesson_7_5::printStrokedString(char *s)
{
	GLsizei len = strlen(s);
	glCallLists(len, GL_BYTE, (GLbyte *)s);
}
