/*
 * OGLApplication.cpp
 *
 *  Created on: Sep 30, 2012
 *      Author: Andrew Zhabura
*/

#include "OGLApplication.h"

// if BPP is 0, it will be set to maximum possible
#define SURFACE_BPP		24

#define INIT_W		500
#define INIT_H		500
#define INIT_LESSON		26

OGL_Application::OGL_Application()
:	m_surface (NULL)
,	m_videoFlags (0)
,	m_breakReason(0)
,	m_isActive(true)
,	m_width(INIT_W)
,	m_height(INIT_H)
,	m_bpp(SURFACE_BPP)
,	m_OGL_Consumer(NULL)
,	m_curLesson(INIT_LESSON)
{
}

OGL_Application::~OGL_Application()
{
	// clean up the window
	SDL_Quit( );
}

void OGL_Application::init()
{
	// initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		fprintf( stderr, "Video initialization failed: %s\n",
				SDL_GetError( ) );
		m_breakReason = -1;
		return;
	}

	// this holds some info about our display
	const SDL_VideoInfo *m_videoInfo;

	// Fetch the video info
	m_videoInfo = SDL_GetVideoInfo( );

	if ( !m_videoInfo )
	{
		fprintf( stderr, "Video query failed: %s\n",
				SDL_GetError( ) );
		m_breakReason = -1;
		return;
	}

	// the flags to pass to SDL_SetVideoMode
	m_videoFlags  = SDL_OPENGL;          // Enable OpenGL in SDL
	m_videoFlags |= SDL_GL_DOUBLEBUFFER; // Enable double buffering
	m_videoFlags |= SDL_HWPALETTE;       // Store the palette in hardware
	m_videoFlags |= SDL_RESIZABLE;       // Enable window resizing

	// This checks to see if surfaces can be stored in memory
	if ( m_videoInfo->hw_available )
		m_videoFlags |= SDL_HWSURFACE;
	else
		m_videoFlags |= SDL_SWSURFACE;

	// This checks if hardware blits can be done
	if ( m_videoInfo->blit_hw )
		m_videoFlags |= SDL_HWACCEL;

	// Sets up OpenGL double buffering
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	// get a SDL surface
	m_surface = SDL_SetVideoMode( m_width, m_height, m_bpp,
			m_videoFlags );

	// Verify there is a surface
	if ( !m_surface )
	{
		fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
		m_breakReason = -1;
		return;
	}

	m_OGL_Consumer = new OGL_Consumer;

	m_OGL_Consumer->initGL();
}

int OGL_Application::exec()
{
	// the start lesson
	m_OGL_Consumer->setLesson(m_curLesson);
	SDL_WM_SetCaption(m_OGL_Consumer->getLessonName(), NULL);
	resizeWindow( INIT_W, INIT_H );

	// used to collect events
	SDL_Event event;

	// wait for events
	while ( !m_breakReason )
	{
		// handle the events in the queue

		while ( SDL_PollEvent( &event ) )
		{
			switch( event.type )
			{
				case SDL_ACTIVEEVENT:
					// Something's happend with our focus
					// If we lost focus or we are iconified, we
					// shouldn't draw the m_surface

					if ( event.active.gain == 0 )
						m_isActive = false;
					else
						m_isActive = true;
					break;
				case SDL_VIDEORESIZE:
					// handle resize m_event
					resizeWindow( event.resize.w, event.resize.h);
					break;
				case SDL_KEYDOWN:
					// handle key presses
					handleKeyPress( &event.key.keysym );
					break;
				case SDL_MOUSEBUTTONDOWN:
					m_OGL_Consumer->sendMessage(m_curLesson, event.button.button, event.button.state,
							event.button.x, event.button.y);
					break;
				case SDL_QUIT:
					// handle quit requests
					m_breakReason = SDL_QUIT;
					break;
				default:
					break;
			}
		}

		// draw the scene
		if ( m_isActive )
		{
			drawGLScene();
		}
	}

	if (m_breakReason == SDL_QUIT)
		m_breakReason = 0;

	return m_breakReason;
}

// function to reset our viewport after a window resize
bool OGL_Application::resizeWindow( int width, int height )
{
	m_width = width;
	m_height = height;

	m_surface = SDL_SetVideoMode( m_width, m_height, m_bpp, m_videoFlags );
	if ( !m_surface )
	{
		fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
		m_breakReason = SDL_VIDEORESIZE;
	}

	m_OGL_Consumer->reshape( m_width, m_height );

	drawGLScene();

	return true;
}

// function to handle key press events
void OGL_Application::handleKeyPress( SDL_keysym *keysym )
{
	if ( m_OGL_Consumer->sendMessage(m_curLesson, keysym->sym, keysym->mod, 0, 0) )
			return;

	switch ( keysym->sym )
	{
		case SDLK_ESCAPE:
			// ESC key was pressed
			m_breakReason = SDL_QUIT;
			break;
		case SDLK_F10:
			// F10 key was pressed
			// this toggles fullm_surface mode
			//int flags = m_surface->flags; /* Save the current flags in case toggling fails */
			m_surface = SDL_SetVideoMode(0, 0, m_bpp, m_surface->flags ^ SDL_FULLSCREEN); /*Toggles FullScreen Mode */
			//if(m_surface == NULL) m_surface = SDL_SetVideoMode(0, 0, 0, flags); /* If toggle FullScreen failed, then switch back */
			if(m_surface == NULL) m_breakReason = SDL_QUIT; /* If you can't switch back for some reason, then epic fail */
			break;
		case SDLK_1:
			m_OGL_Consumer->setLesson(m_curLesson = 0);
			resizeWindow( 250, 250 );
			break;
		case SDLK_2:
			m_OGL_Consumer->setLesson(m_curLesson = 1);
			resizeWindow( 250, 250 );
			break;
		case SDLK_3:
			m_OGL_Consumer->setLesson(m_curLesson = 2);
			resizeWindow( 400, 150 );
			break;
		case SDLK_4:
			m_OGL_Consumer->setLesson(m_curLesson = 3);
			resizeWindow( 350, 150 );
			break;
		case SDLK_5:
			m_OGL_Consumer->setLesson(m_curLesson = 4);
			resizeWindow( 350, 350 );
			break;
		case SDLK_6:
			m_OGL_Consumer->setLesson(m_curLesson = 5);
			resizeWindow( 350, 350 );
			break;
		case SDLK_7:
			m_OGL_Consumer->setLesson(m_curLesson = 6);
			resizeWindow( 350, 350 );
			break;
		case SDLK_8:
			m_OGL_Consumer->setLesson(m_curLesson = 7);
			resizeWindow( 350, 350 );
			break;
		case SDLK_9:
			m_OGL_Consumer->setLesson(m_curLesson = 8);
			resizeWindow( 350, 350 );
			break;
		case SDLK_0:
			m_OGL_Consumer->setLesson(m_curLesson = 9);
			resizeWindow( 350, 350 );
			break;
		case SDLK_q:
			m_OGL_Consumer->setLesson(m_curLesson = 10);
			resizeWindow( 350, 350 );
			break;
		case SDLK_w:
			m_OGL_Consumer->setLesson(m_curLesson = 11);
			resizeWindow( 350, 350 );
			break;
		case SDLK_e:
			m_OGL_Consumer->setLesson(m_curLesson = 12);
			resizeWindow( 450, 150 );
			break;
		case SDLK_r:
			m_OGL_Consumer->setLesson(m_curLesson = 13);
			resizeWindow( 500, 500 );
			break;
		case SDLK_t:
			m_OGL_Consumer->setLesson(m_curLesson = 14);
			resizeWindow( 500, 500 );
			break;
		case SDLK_y:
			m_OGL_Consumer->setLesson(m_curLesson = 15);
			resizeWindow( 500, 500 );
			break;
		case SDLK_u:
			m_OGL_Consumer->setLesson(m_curLesson = 16);
			resizeWindow( 500, 500 );
			break;
		case SDLK_i:
			m_OGL_Consumer->setLesson(m_curLesson = 17);
			resizeWindow( 500, 500 );
			break;
		case SDLK_o:
			m_OGL_Consumer->setLesson(m_curLesson = 18);
			resizeWindow( 500, 500 );
			break;
		case SDLK_p:
			m_OGL_Consumer->setLesson(m_curLesson = 19);
			resizeWindow( 500, 500 );
			break;
		case SDLK_a:
			m_OGL_Consumer->setLesson(m_curLesson = 20);
			resizeWindow( 500, 500 );
			break;
		case SDLK_s:
			m_OGL_Consumer->setLesson(m_curLesson = 21);
			resizeWindow( 500, 500 );
			break;
		case SDLK_d:
			m_OGL_Consumer->setLesson(m_curLesson = 22);
			resizeWindow( 1000, 200 );
			break;
		case SDLK_f:
			m_OGL_Consumer->setLesson(m_curLesson = 23);
			resizeWindow( 500, 500 );
			break;
		case SDLK_g:
			m_OGL_Consumer->setLesson(m_curLesson = 24);
			resizeWindow( 500, 500 );
			break;
		case SDLK_h:
			m_OGL_Consumer->setLesson(m_curLesson = 25);
			resizeWindow( 500, 500 );
			break;
		case SDLK_j:
			m_OGL_Consumer->setLesson(m_curLesson = 26);
			resizeWindow( 500, 500 );
			break;
		case SDLK_k:
			m_OGL_Consumer->setLesson(m_curLesson = 27);
			resizeWindow( 200, 200 );
			break;
		case SDLK_l:
			m_OGL_Consumer->setLesson(m_curLesson = 28);
			resizeWindow( 500, 500 );
			break;
		case SDLK_z:
			m_OGL_Consumer->setLesson(m_curLesson = 29);
			resizeWindow( 1000, 200 );
			break;
		case SDLK_x:
			m_OGL_Consumer->setLesson(m_curLesson = 30);
			resizeWindow( 600, 300 );
			break;
		case SDLK_c:
			m_OGL_Consumer->setLesson(m_curLesson = 31);
			resizeWindow( 500, 500 );
			break;
		case SDLK_v:
			m_OGL_Consumer->setLesson(m_curLesson = 32);
			resizeWindow( 650, 50 );
			break;
		case SDLK_b:
			m_OGL_Consumer->setLesson(m_curLesson = 33);
			resizeWindow( 440, 120 );
			break;
		case SDLK_n:
			m_OGL_Consumer->setLesson(m_curLesson = 34);
			resizeWindow( 650, 50 );
			break;
		default:
			break;
	}

	SDL_WM_SetCaption(m_OGL_Consumer->getLessonName(), NULL);
}

// Here goes our drawing code
void OGL_Application::drawGLScene()
{
	// These are to calculate our fps
	static Uint32 T0     = 0;
	static Uint32 Frames = 0;

	m_OGL_Consumer->drawGLScene();

	/* Draw it to the screen */
	SDL_GL_SwapBuffers( );

	// Gather our frames per second
	Frames++;
	{
		Uint32 t = SDL_GetTicks();
		if (t - T0 >= 5000) {
			float seconds = (t - T0) / 1000.0;
			float fps = Frames / seconds;
			// debug output
			// printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
			T0 = t;
			Frames = 0;
		}
	}
}

