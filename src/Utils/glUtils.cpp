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
    //glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);
    /*      This is the bottom face*/
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    //top face
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    //right face
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    //front face
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    //left face
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    //back face
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
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
    glNormal3f(0,1,0);
    glColor3ub(0, 100, 50);
    glVertex3f(0, 0, 0);
    //glColor3ub(0, 100, 50);
    glVertex3f(0, 0, size);
    //glColor3ub(0, 100, 50);
    glVertex3f(size, 0, size);
    //glColor3ub(0, 100, 50);
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

int loadOBJ(std::string path) {
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;
    std::vector< glm::vec3 > out_vertices;
    std::vector< glm::vec2 > out_uvs;
    std::vector< glm::vec3 > out_normals;
    FILE * file = fopen(path.c_str(), "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
        return false;
    }
    while( 1 ) {
        
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.
        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        } else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        } else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                 &normalIndex[2]);
            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    for( unsigned int i=0; i < vertexIndices.size(); i++ ) {
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        out_vertices.push_back(vertex);
    }
    for( unsigned int i=0; i < normalIndices.size(); i++ ) {
        unsigned int normalIndex = normalIndices[i];
        glm::vec3 normal = temp_normals[ normalIndex-1 ];
        out_normals.push_back(normal);
    }
    for( unsigned int i=0; i < uvIndices.size(); i++ ) {
        unsigned int uvIndex = uvIndices[i];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        out_uvs.push_back(uv);
    }
    GLuint id = glGenLists(1);
    glNewList(id, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    for( unsigned int i=0; i < out_vertices.size(); i++ ) {
        glVertex3f(out_vertices[i].x, out_vertices[i].y, out_vertices[i].z);
        glNormal3f(out_normals[i].x,out_normals[i].y,out_normals[i].z );
    }
    glEnd();
    glEndList();
    return id;
}





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
