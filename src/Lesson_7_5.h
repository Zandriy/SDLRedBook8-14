/*
 * Lesson_7_5.h
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#ifndef LESSON_7_5_H_
#define LESSON_7_5_H_

#include "Lesson.h"

class Lesson_7_5 : public Lesson
{
	typedef struct charpoint {
		GLfloat   x, y;
		int    type;
	} CP;

	enum {
		PT,
		STROKE,
		END
	};

public:
	Lesson_7_5();
	virtual ~Lesson_7_5();

	virtual void reshape(int width, int height);
	virtual void drawGLScene();
	virtual char* getName()
	{
		return (char*)&"7-5. Stroke";
	}

private:
	void draw();
	void drawLetter(CP *l);
	void printStrokedString(char *s);

	GLuint m_base;

	static CP m_Adata[];
	static CP m_Edata[];
	static CP m_Pdata[];
	static CP m_Rdata[];
	static CP m_Sdata[];

	static char* test1;
	static char* test2;
};

#endif /* LESSON_7_5_H_ */
