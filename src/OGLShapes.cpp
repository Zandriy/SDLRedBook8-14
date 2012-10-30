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
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	solidSphere(radius,slices, stacks);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OGLShapes::solidSphere(GLdouble radius,GLint slices, GLint stacks)
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

	const int coordsPerPoint = 3;
	const int arrCoordSize = (slices * stacks + 2/*poles*/) * coordsPerPoint;

	GLfloat * points = new GLfloat[ arrCoordSize ];
	GLfloat * normals = new GLfloat[ arrCoordSize ];
	GLuint * topPoleIndices = new GLuint[ stacks+2 ];
	GLuint * downPoleIndices = new GLuint[ stacks+2 ];

	spherePoints(radius, slices, stacks, points);
	spherePoints(1.0, slices, stacks, normals);

	GLuint ** interIndices;

	if (slices > 1)
	{
		interIndices = new GLuint * [ slices-1 ];

		for (int i = 0; i < slices-1; ++i)
			interIndices[i] = new GLuint[ (stacks+1)*2 ];
	}


	// pole slices
	for(int i = 0; i < stacks+2; ++i)
	{
		if (i ==stacks+1)
		{
			topPoleIndices[i] = 1;
			downPoleIndices[i] = (arrCoordSize / coordsPerPoint) - 1 - 1;
		}
		else
		{
			topPoleIndices[i] = i;
			downPoleIndices[i] = (arrCoordSize / coordsPerPoint) - 1 - i;
		}
	}

	// belt
	if (slices > 1)
	{
		for(int i = 0; i < stacks+1; ++i)
		{
			if ( i == stacks )
			{
				interIndices[0][i*2] = 1;
				interIndices[0][i*2+1] = stacks+1;
			}
			else
			{
					interIndices[0][i*2] = i+1;
					interIndices[0][i*2+1] = stacks+i+1;
			}
		}


		for (int i = 1; i < slices-1; ++i)
		{
			for(int j = 0; j < (stacks+1)*2; ++j )
				interIndices[i][j] = interIndices[i-1][j] + stacks;
		}
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(coordsPerPoint, GL_FLOAT, 0, points);
	glNormalPointer(GL_FLOAT, 0, normals);

	glDrawElements(GL_TRIANGLE_FAN, stacks+2, GL_UNSIGNED_INT, topPoleIndices);

	glDrawElements(GL_TRIANGLE_FAN, stacks+2, GL_UNSIGNED_INT, downPoleIndices);

	if (slices > 1)
	{
		for (int i = 0; i < slices-1; ++i)
			glDrawElements(GL_QUAD_STRIP, (stacks+1)*2, GL_UNSIGNED_INT, interIndices[i]);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	delete [] points;
	delete [] normals;
	delete [] topPoleIndices;
	delete [] downPoleIndices;

	if (slices > 1)
	{
		for (int i = 1; i < slices-1; ++i)
			delete [] interIndices[i];

		delete [] interIndices;
	}
}

void OGLShapes::spherePoints(GLdouble radius,GLint slices, GLint stacks, GLfloat *points)
{
	const int offsetY = 1;
	const int offsetZ = 2;
	const int coordsPerPoint = 3;
	const float stackAngle = 2 * M_PI / stacks;
	const GLdouble Zstep = radius * 2 / (slices + 1);
	const int arrCoordSize = (slices * stacks + 2/*poles*/) * coordsPerPoint;

	int upX = 0;
	int downX = arrCoordSize - coordsPerPoint;

	GLfloat currZ = radius;
	// radius on the current slice
	GLfloat currR = 0;

	// poles X and Y
	points[upX] = points[upX+offsetY] = points[downX] = points[downX+offsetY] = currR;
	// poles Z
	points[upX+offsetZ] = currZ;
	points[downX+offsetZ] = -currZ;

	// calculate all points
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

		downX = arrCoordSize - coordsPerPoint * ( (i/2+1) * (stacks) + 2 );

		for(int j = 0; j < stacks; ++j)
		{
			upX += coordsPerPoint;
			downX += coordsPerPoint;

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

	// Debug output
#if 0
	std::cout << "++++++++++++++++++++++++++++++++++++\n";
	std::cout << "++++++++++++++++= " << radius << " =+++++++++++++++\n";
	std::cout << "++++++++++++++++++++++++++++++++++++\n";
	for (upX = 0; upX < arrCoordSize; upX+=coordsPerPoint)
	{
		std::cout << points[upX] << "\t" << points[upX+offsetY]
		                                           << "\t" << points[upX+offsetZ] << std::endl;
	}
#endif
}
