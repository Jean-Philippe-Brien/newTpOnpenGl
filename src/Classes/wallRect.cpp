//
// Created by jean- on 2019-12-10.
//

#include "wallRect.h"

wallRect::wallRect(std::vector<char>* map, int planeSize) {
    int i = 0, j = 0, k = 0;
    //pointWall.push_back(new glm::vec3(0.5, 0, 0.5));
    //pointWall.push_back(new glm::vec3(1.5, 0, 0.5));
    for (auto c : *map) {
        //std::cout << ((int)c - 48) << std::endl;
        if(c != '0') {
            glm::vec3 pos(k, 0, j);
            addCube(pos);
        }

        i++, k++;
        if (i >= planeSize) { //If we reach the end of the plane, move "up" to next "x"
            j++;
            i = 0;
            k = 0;
        }
    }
}

void wallRect::addCube(glm::vec3 pos) {
    pointWall.push_back(new glm::vec3(pos.x,pos.y,pos.z));
}


