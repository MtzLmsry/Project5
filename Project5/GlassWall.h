#pragma once
#pragma once
#include <GL/freeglut.h>

class GlassWall {
public:
    float x, y, z, w, h ;
    bool vertical;

    GlassWall(float _x, float _y, float _z, float _w, float _h, bool _v)
        : x(_x), y(_y),  z(_z), w(_w), h(_h), vertical(_v) {}

    void draw() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);

        glColor4f(0.6f, 0.8f, 1.0f, 0.35f);

        glBegin(GL_QUADS);
        if (!vertical) {
            // front or back wall
            glVertex3f(x - w / 2, y, z);
            glVertex3f(x + w / 2, y, z);
            glVertex3f(x + w / 2, y + h, z);
            glVertex3f(x - w / 2, y + h, z);
        }
        else {
            // left or right wall
            glVertex3f(x, y, z - w / 2);
            glVertex3f(x, y, z + w / 2);
            glVertex3f(x, y + h, z + w / 2);
            glVertex3f(x, y + h, z - w / 2);
        }
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_BLEND);
    }
};

