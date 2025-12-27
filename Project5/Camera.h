#pragma once
#include <GL/freeglut.h>
#include <cmath>

class Camera {
public:
    float x, y, z;
    float yaw, pitch;
    float speed;
    float sensitivity;
    float step = 0.3f;

    Camera() {
        x = 0; y = 2; z = 8;
        yaw = -90.0f;
        pitch = 0.0f;
        speed = 0.3f;
        sensitivity = 0.2f;
    }

    void apply() {
        float frontX = cos(yaw * 3.14159f / 180.0f) * cos(pitch * 3.14159f / 180.0f);
        float frontY = sin(pitch * 3.14159f / 180.0f);
        float frontZ = sin(yaw * 3.14159f / 180.0f) * cos(pitch * 3.14159f / 180.0f);

        gluLookAt(
            x, y, z,
            x + frontX, y + frontY, z + frontZ,
            0, 1, 0
        );
    }

    void moveForward() {
        x += cos(yaw * 3.14159f / 180.0f) * speed;
        z += sin(yaw * 3.14159f / 180.0f) * speed;
    }

    void moveBackward() {
        x -= cos(yaw * 3.14159f / 180.0f) * speed;
        z -= sin(yaw * 3.14159f / 180.0f) * speed;
    }

    void moveLeft() {
        x += cos((yaw - 90) * 3.14159f / 180.0f) * speed;
        z += sin((yaw - 90) * 3.14159f / 180.0f) * speed;
    }

    void moveRight() {
        x += cos((yaw + 90) * 3.14159f / 180.0f) * speed;
        z += sin((yaw + 90) * 3.14159f / 180.0f) * speed;
    }

    void moveUp() {
        y += step;

    }

    void moveDown() {
        y -= step;

    }


    void mouseLook(float dx, float dy) {
        yaw += dx * sensitivity;
        pitch -= dy * sensitivity;

        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;
    }
};