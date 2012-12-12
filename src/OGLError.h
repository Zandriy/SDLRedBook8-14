/*
 * OGLError.h
 *
 *  Created on: Dec 13, 2012
 *      Author: main
 */

#ifndef OGLERROR_H_
#define OGLERROR_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <map>
#include <string>

class OGLError
{
public:
	OGLError()
	{
		// The value of this symbolic constant is guaranteed to be 0.
		errMap[ GL_NO_ERROR ] = "No error has been recorded.";
		// The offending command is ignored and has no other side effect than to set the error flag.
		errMap[ GL_INVALID_ENUM ] = "An unacceptable value is specified for an enumerated argument.";
		// The offending command is ignored and has no other side effect than to set the error flag.
		errMap[ GL_INVALID_VALUE ] = "A numeric argument is out of range.";
		// The offending command is ignored and has no other side effect than to set the error flag.
		errMap[ GL_INVALID_OPERATION ] = "The specified operation is not allowed in the current state.";
		// The offending command is ignored and has no other side effect than to set the error flag.
		errMap[ GL_INVALID_FRAMEBUFFER_OPERATION ] = "The framebuffer object is not complete.";
		// The state of the GL is undefined, except for the state of the error flags, after this error is recorded.
		errMap[ GL_OUT_OF_MEMORY ] = "There is not enough memory left to execute the command.";

		errMap[ GL_STACK_UNDERFLOW ] = "An attempt has been made to perform an operation that would cause an internal stack to underflow.";
		errMap[ GL_STACK_OVERFLOW ] = "An attempt has been made to perform an operation that would cause an internal stack to overflow.";
	}

	bool checkError()
	{
		int err = glGetError();
		if (!err) return true;

		printf (errMap[err].c_str());
		printf ("\n");

		return false;
	}
private:
	std::map<int, std::string> errMap;
};

#endif /* OGLERROR_H_ */
