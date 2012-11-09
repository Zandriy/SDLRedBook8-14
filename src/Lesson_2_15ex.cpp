/*
 * Lesson_2_15ex.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_2_15ex.h"

#define X .525731112119133606
#define Z .850650808352039932

#define VERTICES_QTY	12
#define TRIANGLES_ORDER	20
#define QTY				3

namespace L_2_15ex
{
GLfloat vdata[VERTICES_QTY][QTY] = {
		{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, Z}, {X, 0.0, -Z},
		{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
		{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};

GLuint tindices[TRIANGLES_ORDER][QTY] = {
		{1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
		{1,10,8},{10,3,8},{8,3,5},{3,2,5},{3,7,2},
		{3,10,7},{10,6,7},{6,11,7},{6,0,11},{6,1,0},
		{10,1,6},{11,0,9},{2,11,9},{5,2,9},{11,2,7}
};
}

Lesson_2_15ex::Lesson_2_15ex()
{
}

Lesson_2_15ex::~Lesson_2_15ex() {
	// TODO Auto-generated destructor stub
}

void Lesson_2_15ex::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	glOrtho(-1.0, -1.0, 1.0, 1.0, -1.0, 1.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_2_15ex::drawGLScene()
{
	GLfloat mat_specular[] = { 1.0, 0.0, 0.6, 1.0 };
	GLfloat mat_shininess[] = { 50.0 }; // 0.0 ... 128.0
	GLfloat light_position1[] = { 2.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2[] = {-2.0,-1.0, 2.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);

	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT2);

	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT2);
}

void Lesson_2_15ex::draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < TRIANGLES_ORDER; ++i )
	{
		glNormal3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][0]][0]);
		glVertex3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][0]][0]);

		glNormal3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][1]][0]);
		glVertex3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][1]][0]);

		glNormal3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][2]][0]);
		glVertex3fv(&L_2_15ex::vdata[L_2_15ex::tindices[i][2]][0]);
	}
	glEnd();
}
