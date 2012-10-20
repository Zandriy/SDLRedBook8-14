/*
 * prg.cpp
 *
 *  Created on: Oct 6, 2012
 *      Author: Andrew Zhabura
 */

#include "OGLApplication.h"
#include "SDL_OGLConfig.h"

int SDL_main(int argc, char ** argv)
{
    fprintf(stdout,"Version %d.%d\n",
            SDL_OGL_VERSION_MAJOR,
            SDL_OGL_VERSION_MINOR);

	OGL_Application app;

	app.init();

	return app.exec();
}
