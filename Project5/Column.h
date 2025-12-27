#pragma once
#define WIN_LEAN_AND_MEAN
#include<cmath>
#include<Windows.h>
#include<GL/freeglut.h>
#include<math.h>
class Column
{
public:
	float x, z;

	Column(float _x, float _z): x(_x), z(_z){}

    void draw() {
        glPushMatrix();
        glTranslatef(x, 2.5f, z);   // фбнкх фен Чсицс
        glScalef(0.5f, 5.0f, 0.5f); // куцЯ ицэс
        glColor3f(0.8f, 0.8f, 0.8f);
        glutSolidCube(1.0f);
        glPopMatrix();
	}
};

