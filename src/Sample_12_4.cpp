/*
 * Sample_12_4.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_12_4.h"
#include "OGLShapes.h"

#include <cmath>

#define	imageWidth 64
#define	imageHeight 64
GLubyte image[3*imageWidth*imageHeight];

void makeImage(void)
{
	int i, j;
	float ti, tj;

	for (i = 0; i < imageWidth; i++) {
		ti = 2.0*3.14159265*i/imageWidth;
		for (j = 0; j < imageHeight; j++) {
			tj = 2.0*3.14159265*j/imageHeight;

			image[3*(imageHeight*i+j)] = (GLubyte) 127*(1.0+sin(ti));
			image[3*(imageHeight*i+j)+1] = (GLubyte) 127*(1.0+cos(2*tj));
			image[3*(imageHeight*i+j)+2] = (GLubyte) 127*(1.0+cos(ti+tj));
		}
	}
}

Sample_12_4::Sample_12_4()
{
}

Sample_12_4::~Sample_12_4()
{
}

void Sample_12_4::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
				5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
				5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Sample_12_4::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(85.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
}

void Sample_12_4::initlights()
{
	GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
	GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void Sample_12_4::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
			0, 1, 12, 4, &ctrlpoints[0][0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,
			0, 1, 4, 2, &texpts[0][0][0]);
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	makeImage();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0,
			GL_RGB, GL_UNSIGNED_BYTE, image);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_FLAT);
	initlights();       /* for lighted version only */
}

void Sample_12_4::restoreGL()
{
	glPopAttrib();
}
