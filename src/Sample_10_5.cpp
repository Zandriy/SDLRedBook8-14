/*
 * Sample_10_5.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: Andrew Zhabura
 */

#include "Sample_10_5.h"
#include "OGLShapes.h"
#include "OGLInspector.h"
#include <SDL/SDL.h>

#define SPHERE_FACES 128
#define PROJ_SIZE 8
#define TIME_JITTER_STEPS 15
#define FULL_ROT 0
#define SCALE_FACTOR 1.0


Sample_10_5::Sample_10_5()
{
}

Sample_10_5::~Sample_10_5()
{
}

void Sample_10_5::reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	if(w<=h)
		glOrtho(-PROJ_SIZE/2,PROJ_SIZE/2,
				-(PROJ_SIZE/2)*h/w,(PROJ_SIZE/2)*h/w,-10.0,10.0);
	else
		glOrtho(-PROJ_SIZE/2*w/h,(PROJ_SIZE/2)*w/h,
				-(PROJ_SIZE/2),PROJ_SIZE/2,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Sample_10_5::draw()
{
	GLfloat correctedProjSize=PROJ_SIZE-3;
	int step;
	GLfloat oneStepTrans=correctedProjSize/TIME_JITTER_STEPS;
	GLfloat oneStepRot=FULL_ROT/TIME_JITTER_STEPS;

	glClear(GL_COLOR_BUFFER_BIT|GL_ACCUM_BUFFER_BIT);
	for(step=0;step<=TIME_JITTER_STEPS;step++)
	{
		glClear(GL_DEPTH_BUFFER_BIT);
		displayObjects(-correctedProjSize/2+oneStepTrans*step,
				oneStepRot*step);
		if(step!=TIME_JITTER_STEPS)
			glAccum(GL_LOAD,0.9);
		else
			glAccum(GL_LOAD,1.0);
		glAccum(GL_RETURN,1.0);
	}
	glAccum(GL_RETURN,1.0);

}

void Sample_10_5::initGL()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	GLfloat mat_ambient[]={0.8,0.8,0.8,1.0};
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat light_position[]={0.0,0.0,10.0,1.0};
	GLfloat lm_ambient[]={0.2,0.2,0.2,1.0};

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialf(GL_FRONT,GL_SHININESS,50.0);

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lm_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_RESCALE_NORMAL);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearAccum(0.0,0.0,0.0,0.0);
}

void Sample_10_5::restoreGL()
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_RESCALE_NORMAL);

	glPopAttrib();
}

bool Sample_10_5::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_b:
		OGLInspector::BuffersReport();
		break;
	default:
		return false;
		break;
	}

	drawGLScene();
	return true;
}

void Sample_10_5::displayObjects(GLfloat xoffset,GLfloat yrot)
{
	GLfloat torus1_diffuse[]={1.0,0.0,0.0,1.0};
	GLfloat torus2_diffuse[]={1.0,0.7,0.7,1.0};
	GLfloat sphere_diffuse[]={1.0,1.0,1.0,1.0};

	glLoadIdentity();
	glTranslatef(xoffset,0.0,0.0);
	glRotatef(yrot,0.0,1.0,0.0);
	glScalef(SCALE_FACTOR,SCALE_FACTOR,SCALE_FACTOR);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,torus1_diffuse);
	OGLShapes::solidTorus(0.3,0.55,SPHERE_FACES,SPHERE_FACES);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,torus2_diffuse);
	OGLShapes::solidTorus(0.35,0.45,SPHERE_FACES,SPHERE_FACES);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,sphere_diffuse);
	OGLShapes::solidSphere(0.4,SPHERE_FACES,SPHERE_FACES);
}

