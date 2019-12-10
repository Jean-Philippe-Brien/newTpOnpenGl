//
// Created by ssohy on 12/5/2019.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include "glUtils.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <fstream>

//Draws a simple 1x1 Cube with its origin in the center.
void drawCube() {
    glBegin(GL_QUADS);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(+1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();
    
}
//Draws a "thin" Cube, Param dir =  1->x 2->y 3->z
void drawWall(int length, int dir) {
    glPushMatrix();
    for (int i = 0; i < length; i++) {
        drawCube();
        switch (dir) {
            case 1:
                glTranslatef(2, 0, 0);
                break;
            case 2:
                glTranslatef(0, 2, 0);
                break;
            case 3:
                glTranslatef(0, 0, 2);
                break;
            default:
                break;
        }
    }
    glPopMatrix();
}
//Draws a simple Triangle with its origin in the center.
void drawTriangle() {
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0, -0.5f);
    glVertex3f(-0.5f, 0, 0);
    glVertex3d(0, 1, 0);
    glVertex3d(0, 0, 0.5f);
    glVertex3d(0.5f, 0, 0);
    glVertex3d(0, 1, 0);
    glVertex3f(0, 0, -0.5f);
    glEnd();
}
//Draws a simple Triangle with another one upside down below it.
void drawDiamond() {
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0, -0.5f);
    glVertex3f(-0.5f, 0, 0);
    glVertex3d(0, 1, 0);
    glVertex3d(0, 0, 0.5f);
    glVertex3d(0.5f, 0, 0);
    glVertex3d(0, 1, 0);
    glVertex3f(0, 0, -0.5f);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0, -0.5f);
    glVertex3f(-0.5f, 0, 0);
    glVertex3d(0, -1, 0);
    glVertex3d(0, 0, 0.5f);
    glVertex3d(0.5f, 0, 0);
    glVertex3d(0, -1, 0);
    glVertex3f(0, 0, -0.5f);
    glEnd();
}
//Draws a 2D Circle
void drawCircle(float k, float r, float h) {
    float x, y;
    glBegin(GL_LINES);
    for (int i = 0; i < 180; i++) {
        x = r * cos(i) - h;
        y = r * sin(i) + k;
        glVertex3f(x + k, y - h, 0);
        
        x = r * cos(i + 0.1) - h;
        y = r * sin(i + 0.1) + k;
        glVertex3f(x + k, y - h, 0);
    }
    glEnd();
}
//Draws a flat, square plane.  Used in ``drawMap()``
void drawPlane(float size) {
    glBegin(GL_QUADS);
    glColor3ub(0, 100, 50);
    glVertex3f(0, 0, 0);
    glColor3ub(0, 100, 50);
    glVertex3f(0, 0, size);
    glColor3ub(0, 100, 50);
    glVertex3f(size, 0, size);
    glColor3ub(0, 100, 50);
    glVertex3f(size, 0, 0);
    glEnd();
}
//Draws a Rectangle using 2  1x1 Cubes side by side. Param dir =  1->x 2->y 3->z
void drawRect(int length, int dir) {
    switch (dir) {
        case 1: //Rect towards "x"
            for (int i = 0; i < length; i++) {
                glPushMatrix();
                drawCube();
                glTranslatef(1, 0, 0);
                drawCube();
                glPopMatrix();
            }
            break;
        case 2: //Rect towards "y"
            for (int i = 0; i < length; i++) {
                glPushMatrix();
                drawCube();
                glTranslatef(0, 1, 0);
                drawCube();
                glPopMatrix();
            }
            break;
        case 3: //Rect towards "y"
            for (int i = 0; i < length; i++) {
                glPushMatrix();
                drawCube();
                glTranslatef(0, 0, 1);
                drawCube();
                glPopMatrix();
            }
            break;
    }
}
//Draws an Axe (Unity x,y,z) at (0,0)
void drawAxe() {
    glPushMatrix();
//    glScalef(1,3,3);
    glBegin(GL_LINES);
    //axe X
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    
    //axe Y
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);
    
    //axe Z
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    
    glEnd();
    glPopMatrix();
}
//Renders a Plane filled with walls/cubes/towers.               Param planeSize -> Obtained by loading the file using the code in next Method.
void drawMap(float planeSize, std::vector<char> mapData) {
 
    float i = 0, j = 0, k = 0;
    //Draw flat plane
    glPushMatrix();
    drawAxe();
    drawPlane(planeSize);
    glPopMatrix();
    
    //Draw cubes on the plane
    glPushMatrix(); // ** for each char in mapData, place proper cube.
    for (auto c : mapData) {
        switch (c) {
            case '0':
                break;
            case '1':
                glPushMatrix();
                glColor3ub(80, 80, 80);
                glTranslatef(k + .5, 0.5, j + .5);
                glScalef(0.5, 0.5, 0.5);
                drawCube();
                glPopMatrix();
                break;
            case '2':
                for (float h = 0; h < 2; h++) {
                    glPushMatrix();
                    glColor3ub(80, 80, 80);
                    glTranslatef(k + .5, h + .5, j + .5);
                    glScalef(0.5, 0.5, 0.5);
                    drawCube();
                    glPopMatrix();
                }
                break;
            case '3':
                for (float h = 0; h < 3; h++) {
                    glPushMatrix();
                    if(h<2) {glColor3ub(50, 50, 50);
                    }else{glColor3ub(120, 120, 120);}
                    glTranslatef(k + .5, h + .5, j + .5);
                    glScalef(0.5, 0.5, 0.5);
                    drawCube();
                    glPopMatrix();
                }
                break;
            case '4':
                for (float h = 0; h < 4; h++) {
                    glPushMatrix();
                    glColor3ub(150, 150, 150);
                    glTranslatef(k + .5, h + .5, j + .5);
                    glScalef(0.5, 0.5, 0.5);
                    drawCube();
                    glPopMatrix();
                }
                break;
            case '5':
                glPushMatrix();
                glColor3ub(100, 100, 100);
                glTranslatef(k + .5, 0.5, j + .5);
                glScalef(0.5, 0.5, 0.1);
                drawCube();
                glPopMatrix();
                break;
            case '6':
                glPushMatrix();
                glColor3ub(100, 100, 100);
                glTranslatef(k + .5, 0.5, j + .5);
                glScalef(0.1, 0.5, 0.5);
                drawCube();
                glPopMatrix();
                break;
            default:
                break;
        }
        i++,k++;
        if (i >= planeSize) { //If we reach the end of the plane, move "up" to next "x"
            j++;
            i = 0;
            k = 0;
        }
    }
    glPopMatrix();
}   //   mapData   -> Obtained same way as planeSize.

//This is **NOT**  a USABLE function. This code is to be implemented in the programs main to load the mapData properly and easily.
void codeToLoadFile(){
    float planeSize=1;
    std::vector<char> *mapList = new std::vector<char>();
    std::ifstream file("assets/cityMap.txt"); //change file name here to test,   ** Need to implement event based file selection **
    if (file) {
        char c;
        while (file.get(c)) {
            if(!isspace(c)){//Check if this char is a '/n'
                mapList->push_back(c);
            }else{planeSize++;}//If so increment Plane size
        }
    } else {        //Error if no file is loaded
        std::cout << "no file loaded" << std::endl;
    }
    mapList->shrink_to_fit();
}
