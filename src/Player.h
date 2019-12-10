//
// Created by jean- on 2019-12-07.
//

#ifndef MONPROJETSDL_PLAYER_H
#define MONPROJETSDL_PLAYER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <fstream>
#include "Classes/Entity.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include "Utils/glUtils.h"
#include <string>

class Player: Entity {
private:
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
    std::vector< glm::vec3 > out_vertices;
    std::vector< glm::vec2 > out_uvs;
    std::vector< glm::vec3 > out_normals;
    int loadOBJ(std::string path);
public:
    Player(const glm::vec3 pos);
    void movement(bool forward);
    void setPos(const glm::vec3 &pos) override;
    const glm::vec3 &getPos() const override;
    float getRotation() const override;
    void setRotation(float rotation) override;
    void drawEntity() override;
    float getCanonRotation() const override;
    void setCanonRotation(float canonRotation) override;
    ~Player();

};


#endif //MONPROJETSDL_PLAYER_H
