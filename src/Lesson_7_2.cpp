/*
 * Lesson_7_2.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_7_2.h"

#include <SDL/SDL.h>

Lesson_7_2::Lesson_7_2()
: m_listName(0)
{
}

Lesson_7_2::~Lesson_7_2() {
	// TODO Auto-generated destructor stub
}

void Lesson_7_2::reshape(int width, int height)
{
	   glViewport(0, 0, width, height);
	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   if (width <= height)
	      gluOrtho2D (0.0, 2.0, -0.5 * (GLfloat) height/(GLfloat) width,
	         1.5 * (GLfloat) height/(GLfloat) width);
	   else
	      gluOrtho2D (0.0, 2.0 * (GLfloat) width/(GLfloat) height, -0.5, 1.5);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
}

void Lesson_7_2::drawGLScene()
{
	glPushMatrix();

	if (!m_listName)
	{
		   m_listName = glGenLists (1);
		   glNewList (m_listName, GL_COMPILE);
		      glColor3f (1.0, 0.0, 0.0);  /*  current color red  */
		      glBegin (GL_TRIANGLES);
		      glVertex2f (0.0, 0.0);
		      glVertex2f (1.0, 0.0);
		      glVertex2f (0.0, 1.0);
		      glEnd ();
		      glTranslatef (1.5, 0.0, 0.0); /*  move position  */
		   glEndList ();
	}
	glShadeModel(GL_FLAT);

	draw();

	glShadeModel(GL_SMOOTH);

	glPopMatrix();
}

void Lesson_7_2::draw()
{
	   GLuint i;

	   glClear (GL_COLOR_BUFFER_BIT);
	   glColor3f (0.0, 1.0, 0.0);  /*  current color green  */
	   for (i = 0; i < 10; i++)    /*  draw 10 triangles    */
	      glCallList (m_listName);
	   drawLine ();  /*  is this line green?  NO!  */
	                 /*  where is the line drawn?  */
}

void Lesson_7_2::drawLine()
{
   glBegin (GL_LINES);
   glVertex2f (0.0, 0.5);
   glVertex2f (15.0, 0.5);
   glEnd ();
}
