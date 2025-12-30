#pragma once
#define WIN_LEAN_AND_MEAN
#include<cmath>
#include<Windows.h>
#include<GL/freeglut.h>
#include<math.h>
#include "Camera.h"
#include "Section.h"
#include "Column.h"
#include "GlassWall.h"
class Scene
{
	Camera camera;

	Section section[4] = {
		Section(-6, -6),
		Section( 6, -6),
		Section(-6,  6),
		Section( 6,  6)
	};

	Column column[4] = {
		Column(-4,0),
		Column(4,0),
		Column(0,-4),
		Column(0,4)
	};

	GlassWall glasswall[4] = {
		GlassWall(0, 0, -10, 20, 4, false), // √„«„
		GlassWall(0, 0, 10, 20, 4, false), // Œ·›
		GlassWall(-10, 0, 0, 20, 4, true),  // Ì”«—
		GlassWall(10, 0, 0, 20, 4, true),  // Ì„Ì‰
	};
};

