//
// Created by ssohy on 12/5/2019.
//

#ifndef FIRST3D_GLUTILS_H
#define FIRST3D_GLUTILS_H

#include "Include.h"
#include <vector>

void drawCube();

void drawTriangle();

void drawDiamond();

void drawWall(int length, int dir);

void drawCircle(float k, float r, float h);

void drawPlane(float size);

void drawRect(int length, int dir);

void drawAxe();

void drawMap(float planeSize, std::vector<char>* mapData) ;

int loadOBJ(std::string path);

#endif //FIRS&T3D_GLUTILS_H
