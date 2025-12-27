#pragma once
#pragma once
#include <GL/freeglut.h>

class GlassWall {
public:
    float x, z, w, h;
    bool vertical;

    GlassWall(float _x, float _z, float _w, float _h, bool _v)
        : x(_x), z(_z), w(_w), h(_h), vertical(_v) {}

    void draw() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);

        glColor4f(0.6f, 0.8f, 1.0f, 0.35f);

        glBegin(GL_QUADS);
        if (!vertical) {
            // √„«„Ì / Œ·›Ì
            glVertex3f(x - w / 2, 0, z);
            glVertex3f(x + w / 2, 0, z);
            glVertex3f(x + w / 2, h, z);
            glVertex3f(x - w / 2, h, z);
        }
        else {
            // Ì„Ì‰ / Ì”«—
            glVertex3f(x, 0, z - w / 2);
            glVertex3f(x, 0, z + w / 2);
            glVertex3f(x, h, z + w / 2);
            glVertex3f(x, h, z - w / 2);
        }
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_BLEND);
    }
};

