#pragma once
#define WIN_LEAN_AND_MEAN
#include<cmath>
#include<Windows.h>
#include<GL/freeglut.h>
#include<math.h>
class Section
{
public:
	float x, z;

	Section(float _x, float _z): x(_x), z(_z) {}

    void draw() {
        glPushMatrix();
        glTranslatef(x, 0, z);
        glColor3f(0.3f, 0.3f, 0.35f);
        glScalef(8, 0.1f, 8); // √—÷Ì… ›ﬁÿ
        glutSolidCube(1.0);
        glPopMatrix();
    }
};

