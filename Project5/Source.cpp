#include <windows.h>
#include <GL/freeglut.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include<vector>
#include "Camera.h"
#include "Section.h"
#include "Column.h"
#include "GlassWall.h"

Camera camera;
std::vector<Section> sections;
std::vector<Column> columns;
std::vector<GlassWall> walls;
int lastMouseX = -1;
int lastMouseY = -1;


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera.apply();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPos[] = { 0, 10, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    

    for (Section s : sections) s.draw();
    for (Column c : columns) c.draw();
    for (GlassWall w : walls) w.draw();

    glutSwapBuffers();
}

void mouseMotion(int x, int y) {
    if (lastMouseX < 0) {
        lastMouseX = x;
        lastMouseY = y;
        return;
    }

    float dx = x - lastMouseX;
    float dy = y - lastMouseY;

    camera.mouseLook(dx, dy);

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int, int) {
    switch (key)
    {
    case 'w': camera.moveForward();  break;
    case 's': camera.moveBackward(); break;
    case 'd': camera.moveRight();     break;
    case 'a': camera.moveLeft();    break;
    case 'e': camera.moveUp();       break;
    case 'q': camera.moveDown();     break;
    case  27: exit(0);               break;
    default:
        break;
    }
    

    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);


    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat amb[] = { 0.2f,0.2f,0.2f,1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

    // أقسام (أرضية)
    sections.push_back(Section(-4, -4));
    sections.push_back(Section(4, -4));
    sections.push_back(Section(-4, 4));
    sections.push_back(Section(4, 4));

    columns.push_back(Column(-14, -14));
    columns.push_back(Column(14, -14));
    columns.push_back(Column(-14, 14));
    columns.push_back(Column(14, 14));

    // الجدران الأربعة
    walls.push_back(GlassWall(-15, -15, 15, -15, false)); // أمامي
    walls.push_back(GlassWall(-15, 15, 15, 15, false)); // خلفي
    walls.push_back(GlassWall(-15, -15, -15, 15, true)); // يسار
    walls.push_back(GlassWall(15, -15, 15, 15, true)); // يمين
}

void reshape(int w, int h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / h, 0.1, 500.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Car Showroom");
    glutSetCursor(GLUT_CURSOR_NONE);

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}