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
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	solidCube(size);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OGLShapes::solidCube(GLdouble size)
{
	size = size > 0 ? size : size * -1;
	size /= 2;


	GLfloat vertices[] = {
			-size,  -size,  -size,
			size, -size,  -size,
			size, size,  -size,
			-size,  size,  -size,
			-size, -size, size,
			size, -size, size,
			size,  size, size,
			-size,  size, size
	};

	GLfloat normals[] = {
			 0.0,  0.0,  1.0,
			 1.0,  0.0,  0.0,
			 0.0, -1.0,  0.0,
			 0.0,  0.0, -1.0,
			-1.0,  0.0,  0.0,
			 0.0,  1.0,  0.0
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

	glNormal3fv(&normals[0]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[0]);
	glNormal3fv(&normals[3]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[4]);
	glNormal3fv(&normals[6]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[8]);
	glNormal3fv(&normals[9]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[12]);
	glNormal3fv(&normals[12]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[16]);
	glNormal3fv(&normals[15]);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &allIndices[20]);

	glDisableClientState(GL_VERTEX_ARRAY);
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

	// draw a sphere
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

	// clean arrays
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

void OGLShapes::wireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	solidTorus(innerRadius, outerRadius, nsides, rings);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void OGLShapes::solidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings)
{
	GLdouble ringR;
	GLdouble normalR;
	GLdouble distToCenter;

	innerRadius = innerRadius > 0.0 ? innerRadius : innerRadius * -1;

	outerRadius = outerRadius > 0.0 ? outerRadius : outerRadius * -1;
	outerRadius = outerRadius == 0.0 ? 0.5 : outerRadius;

	nsides = nsides < 3 ? 3 : nsides;
	rings = rings < 3 ? 3 : rings;

	if (innerRadius == outerRadius)
		outerRadius += 0.1;

	if (innerRadius > outerRadius)
	{
		ringR = innerRadius;
		innerRadius = outerRadius;
		outerRadius = ringR;
	}

	ringR = (outerRadius - innerRadius)/2;
	normalR = 1.0;

	distToCenter = innerRadius + ringR;

	const int offsetY = 1;
	const int offsetZ = 2;
	const int coordsPerPoint = 3;
	const float nsideAngle = 2 * M_PI / nsides;
	const float ringAngle = 2 * M_PI / rings;
	const int arrCoordSize = (rings * nsides) * coordsPerPoint;

	GLfloat * points = new GLfloat[ arrCoordSize ];
	GLfloat * normals = new GLfloat[ arrCoordSize ];

	GLuint ** beltIndices = new GLuint * [ nsides ];

	for (int i = 0; i < nsides; ++i)
		beltIndices[i] = new GLuint[ (rings+1)*2 ];

	int currX = 0;

	// create first ring
	for (int i = 0; i < nsides; ++i)
	{
		points[currX] = ringR * cos(nsideAngle*i) + distToCenter;
		points[currX+offsetY] = 0;
		points[currX+offsetZ] = ringR * sin(nsideAngle*i);

		normals[currX] = normalR * cos(nsideAngle*i);
		normals[currX+offsetY] = 0;
		normals[currX+offsetZ] = normalR * sin(nsideAngle*i);

		currX+=coordsPerPoint;
	}

	// set other rings
	for (int i = 1; i < rings; ++i)
	{
		for (int j = 0; j < nsides; ++j)
		{
			points[currX] = points[j*coordsPerPoint]*cos(ringAngle*i);
			points[currX+offsetY] = points[j*coordsPerPoint]*sin(ringAngle*i);
			points[currX+offsetZ] = points[j*coordsPerPoint+offsetZ];

			normals[currX] = normals[j*coordsPerPoint]*cos(ringAngle*i);
			normals[currX+offsetY] = points[j*coordsPerPoint]*sin(ringAngle*i);
			normals[currX+offsetZ] = normals[j*coordsPerPoint+offsetZ];

			currX+=coordsPerPoint;
		}
	}

	// set first belt
	for (int i = 0; i < rings+1; ++i)
	{
		if (i == rings)
		{
			beltIndices[0][i*2] = 1;
			beltIndices[0][i*2+1] = 0;
		}
		else
		{
			beltIndices[0][i*2] = nsides*i + 1;
			beltIndices[0][i*2+1] = nsides*i;
		}
	}

	// set other belts
	for (int i = 1; i < nsides; ++i)
	{
		for (int j = 0; j < rings+1; ++j)
		{
			if ( i == nsides-1 )
			{
				beltIndices[i][j*2] = beltIndices[0][j*2]-1;
				beltIndices[i][j*2+1] = beltIndices[i-1][j*2+1] + 1;
			}
			else
			{
				beltIndices[i][j*2] = beltIndices[i-1][j*2] + 1;
				beltIndices[i][j*2+1] = beltIndices[i-1][j*2+1] + 1;
			}
		}
	}

	// draw torus
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(coordsPerPoint, GL_FLOAT, 0, points);
	glNormalPointer(GL_FLOAT, 0, normals);

	for (int i = 0; i < nsides; ++i)
			glDrawElements(GL_QUAD_STRIP, (rings+1)*2, GL_UNSIGNED_INT, beltIndices[i]);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	// clean arrays
	delete [] points;
	delete [] normals;

	for (int i = 1; i < nsides; ++i)
			delete [] beltIndices[i];

	delete [] beltIndices;
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
