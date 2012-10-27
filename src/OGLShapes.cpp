/*
 * OGLShapes.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "OGLShapes.h"

#include <cmath>
#include <iostream>

void OGLShapes::wireCube(GLdouble size)
{
	size = size > 0 ? size : size * -1;
	size /= 2;

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat vertices[] = {
			-size, -size,  size,
			 size, -size,  size,
			 size,  size,  size,
			-size,  size,  size,
			-size, -size, -size,
			 size, -size, -size,
			 size,  size, -size,
			-size,  size, -size
	};

	GLubyte allIndices[] = {
			  4, 7, 6, 5
			, 1, 2, 6, 5
			, 0, 1, 5, 4
			, 0, 3, 2, 1
			, 0, 4, 7, 3
			, 2, 3, 7, 6
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);

	glDisableClientState(GL_VERTEX_ARRAY);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OGLShapes::wireSphere(GLdouble radius,GLint slices, GLint stacks)
{
	/*
	radius
	    The radius of the sphere.
	slices
	    The number of subdivisions around the Z axis (similar to lines of longitude).
	stacks
	    The number of subdivisions along the Z axis (similar to lines of latitude).

	if center is 0.0, 0.0, 0.0 then R^2 = x^2 + y^2 + z^2
	*/

	radius = radius > 0.0 ? radius : radius * -1;
	radius = radius == 0.0 ? 1.0 : radius;
	slices = slices < 1 ? 1 : slices;
	stacks = stacks < 3 ? 3 : stacks;

	const int offsetY = 1;
	const int offsetZ = 2;
	const int coordsPerPoint = 3;
	const float stackAngle = 2 * M_PI / stacks;
	const GLdouble Zstep = radius * 2 / (slices + 1);
	const int arrCoordSize = (slices * stacks + 2/*poles*/) * coordsPerPoint;
	const int arrOrderSize = (slices+1) * stacks;

	GLfloat * points = new GLfloat[ arrCoordSize ];
	GLuint * indices = new GLuint[ arrOrderSize ];

	for (int i = 0; i < arrOrderSize; ++i)
		indices[i] = 0;

	int upX = 0;
	int downX = arrCoordSize - coordsPerPoint;

	GLfloat currZ = radius;
	GLfloat currR = 0;

	// poles X and Y
	points[upX] = points[upX+offsetY] = points[downX] = points[downX+offsetY] = currR;
	// poles Z
	points[upX+offsetZ] = currZ;
	points[downX+offsetZ] = -currZ;

	for (int i = 0; i < slices; i+=2)
	{
		currZ -= Zstep;

		// central slice
		if (currZ < Zstep / 2)
		{
			currZ = 0.0;
			currR = radius;
		}
		else
			currR = sqrt(radius*radius - currZ*currZ);

		for(int j = 0; j < stacks; ++j)
		{
			upX += coordsPerPoint;
			downX -= coordsPerPoint;

			points[upX] = currR * cos(stackAngle*j);
			points[upX+offsetY] = currR * sin(stackAngle*j);
			points[upX+offsetZ] = currZ;

			if (0.0 < currZ)
			{
				points[downX] = points[upX];
				points[downX+offsetY] = points[upX+offsetY];
				points[downX+offsetZ] = -currZ;
			}
		}
	}

	std::cout << "++++++++++++++++++++++++++++++++++++\n";
	std::cout << "++++++++++++++++++++++++++++++++++++\n";
	std::cout << "++++++++++++++++++++++++++++++++++++\n";
	for (upX = 0; upX < arrCoordSize; upX+=coordsPerPoint)
	{
		std::cout << points[upX] << "\t" << points[upX+offsetY]
		          << "\t" << points[upX+offsetZ] << std::endl;
	}

	GLuint corn1up, corn2up, corn3up, corn4up;
	GLuint corn1down, corn2down, corn3down, corn4down;
	int indx = 0;

	corn1up = corn2up = 0;
	corn3up = corn2up + 1;
	corn4up = corn3up + 1;
	corn1down = corn2down = (arrCoordSize / coordsPerPoint) - 1;
	corn3down = corn2down - stacks;
	corn4down = corn2down - 1;

	// first and last slice
	int j;
	for(j = 0; j < stacks; ++j)
	{
		if ( j == stacks-1 )
			corn4up = corn2up+1;

		indices[j*4] = corn1up;
		indices[j*4+1] = corn2up;
		indices[j*4+2] = corn3up;
		indices[j*4+3] = corn4up;

		corn3up += 1;
		corn4up = corn3up + 1;

		indices[stacks*4 + j*4] = corn1down;
		indices[stacks*4 + j*4+1] = corn2down;
		indices[stacks*4 + j*4+2] = corn3down;
		indices[stacks*4 + j*4+3] = corn4down;

		corn3down = corn4down;
		corn4down -= 1;
	}
/*
	corn1up += 1;
	corn2up = corn1up + 1;
	corn3up += 1;
	corn4up = corn3up + 1;

	indices[j*4] = corn1up;
	indices[j*4+1] = corn2up;
	indices[j*4+2] = corn3up;
	indices[j*4+3] = corn4up;
	*/

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(coordsPerPoint, GL_FLOAT, 0, points);

	glDrawElements(GL_QUADS, arrOrderSize, GL_UNSIGNED_INT, indices);

	glDisableClientState(GL_VERTEX_ARRAY);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
