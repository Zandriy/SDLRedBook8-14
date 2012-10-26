/*
 * OGLApplication.h
 *
 *  Created on: Sep 30, 2012
 *      Author: Andrew Zhabura
*/

#ifndef OGL_APPLICATION_H_
#define OGL_APPLICATION_H_

#include <SDL/SDL.h>
#include "OGLConsumer.h"

class OGL_Application
{
public:
	OGL_Application();
	~OGL_Application();
	void init();
	int exec();
	bool resizeWindow( int width, int height );
	void handleKeyPress( SDL_keysym *keysym );
	void drawGLScene();
private:
	SDL_Surface *m_surface;
	unsigned int  m_videoFlags;
	int  m_breakReason;
	bool m_isActive;
	unsigned int  m_width;
	unsigned int  m_height;
	unsigned int  m_bpp;
	OGL_Consumer * m_OGL_Consumer;
	unsigned int  m_curLesson;
};

#endif // OGL_APPLICATION_H_
