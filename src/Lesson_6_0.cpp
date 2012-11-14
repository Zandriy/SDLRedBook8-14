/*
 * Lesson_6_0.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_0.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>

Lesson_6_0::Lesson_6_0()
: m_bmp (new BitMapFile)
, m_texture(0)
, m_angle(0.0)
, m_seg(2)
{
	// TODO Auto-generated constructor stub
}

Lesson_6_0::~Lesson_6_0() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_0::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_6_0::drawGLScene()
{
	glEnable(GL_DEPTH_TEST);

	// Create texture index array and load external textures.
	glGenTextures(1, &m_texture);
	loadExternalTextures();

	// Turn on OpenGL texturing.
	glEnable(GL_TEXTURE_2D);

	// Turn on OpenGL blending.
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0, 1.0, 0.0, 0.5);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}

void Lesson_6_0::draw()
{
	   glLoadIdentity();

	   glPushMatrix();

	   if (m_angle >= 360.0 ) m_angle = 0.0;
	   glRotatef(m_angle, 0.0, 1.0, 0.0);

	   glBindTexture(GL_TEXTURE_2D, m_texture);

	   for ( int i = 0; i < m_seg; ++i )
	   {
		   // Map the trees texture onto a vertical rectangle.
		   glBegin(GL_POLYGON);
		   glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
		   glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
		   glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
		   glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
		   glEnd();

		   glRotatef(180.0/m_seg, 0.0, 1.0, 0.0);
	   }

	   glBindTexture(GL_TEXTURE_2D, NULL);

	   glPopMatrix();
}

// Routine to read a bitmap file.
// Works only for uncompressed m_bmp files of 24-bit color.
void Lesson_6_0::getBMPData(std::string filename)
{
   unsigned int size, offset, headerSize;

   // Read input file name.
   std::ifstream infile(filename.c_str(), std::ios::binary);

   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4);

   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &m_bmp->sizeX, 4);
   infile.read( (char *) &m_bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = m_bmp->sizeX * m_bmp->sizeY * 24;
   m_bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) m_bmp->data , size);

   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   {
      temp = m_bmp->data[i];
	  m_bmp->data[i] = m_bmp->data[i+2];
	  m_bmp->data[i+2] = temp;
   }
}


// Load external textures.
void Lesson_6_0::loadExternalTextures()
{
   // Load the texture.
   getBMPData("textures/tree.bmp");

   // Bind trees image to texture.
   glBindTexture(GL_TEXTURE_2D, m_texture);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
   gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, m_bmp->sizeX, m_bmp->sizeY,
	                 GL_RGB, GL_UNSIGNED_BYTE, m_bmp->data);
}

bool Lesson_6_0::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDL_BUTTON_LEFT:
		m_angle += 1.5;
		break;
	case SDL_BUTTON_RIGHT:
		m_angle -= 1.5;
		break;
	default:
		return false;
		break;
	}

	return true;
}
