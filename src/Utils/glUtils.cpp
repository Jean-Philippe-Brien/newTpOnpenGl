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
SDL_Surface * flipSurface(SDL_Surface * surface);

GLuint loadTexture(const char * filename, bool useMipMap){
    GLuint glID;
    SDL_Surface * picture_surface = NULL;
    SDL_Surface *gl_surface = NULL;
    SDL_Surface * gl_fliped_surface = NULL;
    Uint32 rmask, gmask, bmask, amask;
    picture_surface = IMG_Load(filename);
    if (picture_surface == NULL)
        return 0;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif
    SDL_PixelFormat format = *(picture_surface->format);
    format.BitsPerPixel = 32;
    format.BytesPerPixel = 4;
    format.Rmask = rmask;
    format.Gmask = gmask;
    format.Bmask = bmask;
    format.Amask = amask;
    gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);
    // if(!skyBox)
    gl_fliped_surface = flipSurface(gl_surface);
    glGenTextures(1, &glID);
    glBindTexture(GL_TEXTURE_2D, glID);
    if (useMipMap){
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
                          gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
                          gl_fliped_surface->pixels);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_LINEAR);
    }else{
        glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
                     gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
                     gl_fliped_surface->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //if(!skyBox)
    SDL_FreeSurface(gl_fliped_surface);
    SDL_FreeSurface(gl_surface);
    SDL_FreeSurface(picture_surface);
    return glID;
}

SDL_Surface * flipSurface(SDL_Surface * surface){
    int current_line,pitch;
    SDL_Surface * fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                        surface->w,surface->h,
                                                        surface->format->BitsPerPixel,
                                                        surface->format->Rmask,
                                                        surface->format->Gmask,
                                                        surface->format->Bmask,
                                                        surface->format->Amask);
    SDL_LockSurface(surface);
    SDL_LockSurface(fliped_surface);
    pitch = surface->pitch;
    for (current_line = 0; current_line < surface->h; current_line ++){
        memcpy(&((unsigned char* )fliped_surface->pixels)[current_line*pitch],
               &((unsigned char* )surface->pixels)[(surface->h - 1  -
                                                    current_line)*pitch],
               pitch);
    }
    SDL_UnlockSurface(fliped_surface);
    SDL_UnlockSurface(surface);
    return fliped_surface;
}

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
void drawCubeMap(float textureX, float textureY, GLuint idTexture) {
    //glColor3f(0.5,0.5,0.5);

    glBindTexture(GL_TEXTURE_2D, idTexture);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 1.0)/8.0);  glVertex3f(-1, 1, 1);
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(-1, -1, 1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(-1, -1, -1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(-1, 1, -1);

    //front
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(-1, 1, -1);
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(-1, -1, -1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(1, -1, -1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(1, 1, -1);

    //right
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(1, 1, 1);
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(1, -1, 1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(1, -1, -1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(1, 1, -1);

    //back
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(-1, 1, 1);
    glTexCoord2f((textureX + 1.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(-1, -1, 1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 0.0)/8.0); glVertex3f(1, -1, 1);
    glTexCoord2f((textureX + 0.0)/6.0, (textureY + 1.0)/8.0); glVertex3f(1, 1, 1);

    //top
     glVertex3f(-1, 1, -1);
     glVertex3f(-1, 1, 1);
     glVertex3f(1, 1, 1);
     glVertex3f(1, 1, -1);

    //bottom
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);

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
void drawPlane(float size, GLuint idTexture) {
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex3f(0, 0, 0);
    glTexCoord2f(0,10); glVertex3f(0, 0, size);
    glTexCoord2f(10,10); glVertex3f(size, 0, size);
    glTexCoord2f(10,0); glVertex3f(size, 0, 0);
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
int drawMap(float planeSize, std::vector<char>* mapData, GLuint idTexture) {
    int compteur = 0;
    float i = 0, j = 0, k = 0;
    //Draw flat plane
    glPushMatrix();
    drawAxe();

    glPopMatrix();
    GLuint id;
    glNewList(id, GL_COMPILE);
    //Draw cubes on the plane
    glPushMatrix(); // ** for each char in mapData, place proper cube.
    for (auto c : *mapData) {
        //std::cout << ((int)c - 48) << std::endl;
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
                for (int h = 0; h < ((int)c - 48); h++) {


                    glPushMatrix();
                    glColor3ub(80, 80, 80);
                    glTranslatef(k , h, j );
                    glScalef(0.5, 0.5, 0.5);
                    drawCubeMap(rand() % 5,rand() % 7,idTexture);
                    glPopMatrix();
                    compteur++;
                }
                break;
            case '7':
                glPushMatrix();
                glColor3ub(100, 100, 100);
                glTranslatef(k, 0.5, j);
                glScalef(0.5, 0.5, 0.1);
                drawCube();
                glPopMatrix();
                compteur++;
                break;
            case '8':
                glPushMatrix();
                glColor3ub(100, 100, 100);
                glTranslatef(k + .5, 0.5, j + .5);
                glScalef(0.1, 0.5, 0.5);
                drawCube();
                glPopMatrix();
                compteur++;
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
    glEndList();
    return id;
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
        glNormal3f(out_normals[i].x,out_normals[i].y,out_normals[i].z );
        glVertex3f(out_vertices[i].x, out_vertices[i].y, out_vertices[i].z);

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
