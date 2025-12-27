
#ifndef GLTEXTURE_H
#define GLTEXTURE_H

//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


class GLTexture
{
public:
    char* texturename;          // «”„ «·’Ê—…
    unsigned int texture[1];    // ID ··‰’Ê—… »«·‹ OpenGL
    int width;                  // ⁄—÷ «·’Ê—…
    int height;                 // ÿÊ· «·’Ê—…
    int channels;               // ⁄œœ «·ﬁ‰Ê«  (RGB / RGBA)

    void Use();                 // · ›⁄Ì· «·‰’Ê—…
    void BuildColorTexture(unsigned char r, unsigned char g, unsigned char b); // ‰’Ê—… »·Ê‰ À«» 
    void Load(const char* filename); //  Õ„Ì· ’Ê—… PNG / JPG / BMP / TGA
    GLTexture();
    virtual ~GLTexture();
};

#endif

