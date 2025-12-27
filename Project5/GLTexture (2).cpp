#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include "GLTexture.h"
#include <cstring>
#include <cstdio>

GLTexture::GLTexture() : texturename(nullptr), width(0), height(0), channels(0)
{
    texture[0] = 0;
}

GLTexture::~GLTexture()
{
    if (texturename)
        delete[] texturename;
}

void GLTexture::Use()
{
    glBindTexture(GL_TEXTURE_2D, texture[0]);
}

void GLTexture::Load(const char* filename)
{
    if (!filename) return;

    if (texturename)
    {
        delete[] texturename;
        texturename = nullptr;
    }

    // Õ›Ÿ «”„ «·’Ê—…
    size_t len = strlen(filename) + 1;
    texturename = new char[len];
    strcpy_s(texturename, len, filename);

    //  Õ„Ì· «·’Ê—… »«” Œœ«„ stb_image
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
    if (!data)
    {
        MessageBoxA(NULL, "Failed to load texture!", "Error", MB_OK);
        return;
    }

    GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    gluBuild2DMipmaps(GL_TEXTURE_2D, format, width, height, format, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
}

void GLTexture::BuildColorTexture(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned char data[12] = { r, g, b, r, g, b, r, g, b, r, g, b };

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 2, 2, GL_RGB, GL_UNSIGNED_BYTE, data);
}
