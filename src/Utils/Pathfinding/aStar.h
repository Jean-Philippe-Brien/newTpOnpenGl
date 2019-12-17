//
// Created by ssohy on 12/15/2019.
//

#ifndef RUSTBUCKETS_ASTAR_H
#define RUSTBUCKETS_ASTAR_H

#include "../Include.h"
#include "Node.h"
#include "bits/stdc++.h"
class aStar {
public:
    std::vector<Node> nodeMap;
    std::vector<Node> foundPath;
    int parentNodeNumber;
    std::vector<Node> *openSet;
    std::vector<Node> *closedSet;
    int planeSize;
    
    
    aStar();
    aStar(std::vector<Node> nMap,int planeSize);
    void FindPath(glm::vec3 startPos,glm::vec3 targetPos);
    std::vector<Node> getNeighbours(Node* node);
    int GetDistance(Node nodeA,Node nodeB);
    bool Contains(std::vector<Node> nodeList,Node node);
    void RetracePath(Node startNode,Node endNode);
    bool isPathFound(std::vector<Node*> path);
    
    
};


#endif //RUSTBUCKETS_ASTAR_H
