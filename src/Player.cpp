//
// Created by jean- on 2019-12-07.
//

#include "Player.h"
#include "Classes/Entity.h"

Player::Player(const glm::vec3 pos) : Entity(pos) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
    

}

/*int Player::loadOBJ(std::string path) {
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;
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
    glColor3f(0,0,0);
    for( unsigned int i=0; i < out_vertices.size(); i++ ) {
        glVertex3f(out_vertices[i].x, out_vertices[i].y, out_vertices[i].z);
    }
    glEnd();
    glEndList();
    out_normals.clear();
    out_uvs.clear();
    out_vertices.clear();
    return id;
}*/

void Player::movement(bool forward) {
    speed = 0.01;
    if(forward) {
        position.x += speed * cos(rotation * (M_PI / 180));
        position.z -= speed * sin(rotation * (M_PI / 180));
    } else {
    
        position.x -= speed * cos(rotation * (M_PI / 180));
        position.z += speed * sin(rotation * (M_PI / 180));
    }
}

void Player::drawEntity() {
    glPushMatrix();

        glTranslatef(position.x, position.y, position.z);
        glRotatef(rotation, 0, 1, 0);
        drawAxe();
        glRotatef(90,0,1,0);
        glCallList(idBaseThank);
        glRotatef( canonRotation,0,1,0);
        glCallList(idBaseCanon);
    glPopMatrix();
    for(Projectile *p : projectile){
        p->draw();
    }
}

const glm::vec3 &Player::getPos() const {
    return Entity::getPos();
}

void Player::setPos(const glm::vec3 &pos) {
    Entity::setPos(pos);
}

float Player::getRotation() const {
    return Entity::getRotation();
}

void Player::setRotation(float rotation) {
    Entity::setRotation(rotation);
}

Player::~Player() {
    glDeleteLists(idBaseThank, 1);
}

float Player::getCanonRotation() const {
    return Entity::getCanonRotation();
}

void Player::setCanonRotation(float canonRotation) {
    Entity::setCanonRotation(canonRotation);
}

void Player::createProjectile() {
    float p = SDL_GetTicks();
    if(this->lastFire + fireRate < p ) {
        lastFire = SDL_GetTicks();
        projectile.push_back(new Projectile(rotation + canonRotation, position));
    }
}

float Player::getFireRate1() const {
    return fireRate;
}

void Player::setFireRate1(float fireRate) {
    Player::fireRate = fireRate;
}

float Player::getLastFire() const {
    return lastFire;
}

void Player::setLastFire(float lastFire) {
    Player::lastFire = lastFire;
}

