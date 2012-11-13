/*
 * Lesson_5_10.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_10.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>

Lesson_5_10::Lesson_5_10()
: m_diffuseMaterial (new GLfloat[4])
{
	m_diffuseMaterial[0] = 0.5;
	m_diffuseMaterial[1] = 0.5;
	m_diffuseMaterial[2] = 0.5;
	m_diffuseMaterial[3] = 1.0;
}

Lesson_5_10::~Lesson_5_10() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_10::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width<=height)
		glOrtho(-1.5,1.5,-1.5*(GLfloat)height/(GLfloat)width, 1.5*(GLfloat)height/(GLfloat)width,-10.0,10.0);
	else
		glOrtho(-1.5*(GLfloat)width/(GLfloat)height, 1.5*(GLfloat)width/(GLfloat)height,-1.5,1.5,-10.0,10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_10::drawGLScene()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_COLOR_MATERIAL);
}

void Lesson_5_10::draw()
{
	OGLShapes::solidSphere(1.0, 20, 16);
}

bool Lesson_5_10::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDL_BUTTON_LEFT:
		if (mode==SDL_PRESSED) {
			m_diffuseMaterial[0] += 0.1;
			if (m_diffuseMaterial[0] > 1.0)
				m_diffuseMaterial[0] = 0.0;
			glColor4fv(m_diffuseMaterial);
		}
		break;
	case SDL_BUTTON_MIDDLE:
		if (mode==SDL_PRESSED) {
			m_diffuseMaterial[1] += 0.1;
			if (m_diffuseMaterial[1] > 1.0)
				m_diffuseMaterial[1] = 0.0;
			glColor4fv(m_diffuseMaterial);
		}
		break;
	case SDL_BUTTON_RIGHT:
		if (mode==SDL_PRESSED) {
			m_diffuseMaterial[2] += 0.1;
			if (m_diffuseMaterial[2] > 1.0)
				m_diffuseMaterial[2] = 0.0;
			glColor4fv(m_diffuseMaterial);
		}
		break;
	default:
		return false;
		break;
	}

	return true;
}
