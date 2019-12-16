//
// Created by ssohy on 12/15/2019.
//

#include "aStar.h"


aStar::aStar() {
}

aStar::aStar(std::vector<Node> nMap, int planeSize) {
    nodeMap = nMap;
    this->planeSize = planeSize;
}

void aStar::FindPath(glm::vec3 startPos, glm::vec3 targetPos) {
    bool REMOVEME = false;
    
    Node startNode;
    Node targetNode;
    for (Node n : nodeMap) {//Find Nodes corresponding to Start and Target Position
        if (n.getX() == startPos.x && n.getY() == startPos.z) {
            startNode = n;
        } else if (n.getX() == targetPos.x && n.getY() == targetPos.z) {
            targetNode = n;
        }
    }
    openSet = new std::vector<Node>();
   // openSet->shrink_to_fit();
    closedSet = new std::vector<Node>();
    //closedSet->shrink_to_fit();
    
    openSet->push_back(startNode);
    std::cout << openSet->size() << std::endl;
    while (!openSet->empty()) {
        Node *currentNode = &openSet->front();
        int savedI;
        for (int i = 1; i < openSet->size(); i++) {
            if (openSet->at(i).fCost() < currentNode->fCost() ||
                (openSet->at(i).fCost() == currentNode->fCost() &&
                 openSet->at(i).getHCost() < currentNode->getHCost())) {
                currentNode = &openSet->at(i);
                savedI = i;
            }
        }
        
        openSet->erase(openSet->begin() + savedI+1);
        closedSet->push_back(*currentNode);
        
        if (currentNode->getId() == targetNode.getId()) {
            RetracePath(&startNode, &targetNode);
            return;
        }
        
        for (Node neighbour : getNeighbours(currentNode)) {
            
            if (!neighbour.isWalkable() || Contains(*closedSet, neighbour)) {
                continue;
            }
            
            
            int newMovementCost = currentNode->getGCost() + GetDistance(*currentNode, neighbour);
            if (newMovementCost < neighbour.getGCost() || !Contains(*openSet, neighbour)) {
                neighbour.setGCost(newMovementCost);
                neighbour.setHCost(GetDistance(neighbour, targetNode));
                neighbour.fCost();
                Node::setParent(currentNode);
            }
            if (!Contains(*openSet, neighbour)) {
                openSet->push_back(neighbour);
            }
        }
        
    }
}


std::vector<Node> aStar::getNeighbours(Node *node) {
    std::vector<Node> neighbourList;
    std::vector<Node> sortedList;
    for (int i = nodeMap.at(node->getId()).getId() + 1; i < (nodeMap.at(node->getId()).getId() + planeSize+2); i++) {
        sortedList.push_back(nodeMap.at(i));
    }
    if (node->getId() < planeSize) {
        for(int i= node->getId() -1; i>(planeSize-node->getId());i--){
            sortedList.push_back(nodeMap.at(i));
        }
    } else {
        for (int i = nodeMap.at(node->getId()).getId() - 1; i > (nodeMap.at(node->getId()).getId() - planeSize); i--) {
            sortedList.push_back(nodeMap.at(i));
        }
    }
    sortedList.shrink_to_fit();
    
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
                continue;
            }
            int checkX = node->getX() + x;
            int checkY = node->getY() + y;
            
            if (checkX >= 0 && checkX < planeSize && checkY >= 0 && checkY < planeSize) {
                for (Node n : sortedList) {
                    if (n.getX() == checkX && n.getY() == checkY) {
                        neighbourList.push_back(n);
                    }
                }
            }
        }
    }
    
    return neighbourList;
}

bool aStar::Contains(std::vector<Node> nodeList, Node node) {
    for (Node n : nodeList) {
        if (n.getId() == node.getId()) {
            return true;
        }
    }
    return false;
}

void aStar::RetracePath(Node *startNode, Node *endNode) {
    std::vector<Node *> path;
    Node *currentNode = endNode;
    
    while (currentNode->getId() != startNode->getId()) {
        path.push_back(currentNode);
        currentNode = Node::getParent();
    }
    
    std::reverse(path.begin(), path.end());
    
    foundPath = path;
}

int aStar::GetDistance(Node nodeA, Node nodeB) {
    int distX = abs(nodeA.getX() - nodeB.getX());
    int distY = abs(nodeA.getY() - nodeB.getY());
    
    if (distX > distY) {
        return 14 * distY + 10 * (distX - distY);
    } else { return 14 * distX + 10 * (distY - distX); }
}

bool aStar::isPathFound(std::vector<Node*> path) {
    
    return false;
}



