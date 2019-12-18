//
// Created by ssohy on 12/5/2019.
//

#ifndef FIRST3D_GLUTILS_H
#define FIRST3D_GLUTILS_H

#include "Include.h"
#include <vector>
GLuint loadTexture(const char * filename, bool useMipMap);
void drawCubeMap(float textureX, float textureY, GLuint idTexture);
void drawCube();

void drawTriangle();

void drawDiamond();

void drawWall(int length, int dir);

void drawCircle(float k, float r, float h);

void drawPlane(float size, GLuint idTexture);
void drawLifeBar(glm::vec3 pos, float rotation, float pourcentVie, bool player);
void drawRect(int length, int dir);

void drawAxe();

int drawMap(float planeSize, std::vector<char>* mapData, GLuint idTexture);

int loadOBJ(std::string path);

#endif //FIRS&T3D_GLUTILS_H
