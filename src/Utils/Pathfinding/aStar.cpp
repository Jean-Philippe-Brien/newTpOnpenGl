//
// Created by ssohy on 12/15/2019.
//

#include "aStar.h"


aStar::aStar() {
}

aStar::aStar(std::vector<Node> nMap, int planeSize) {
    nodeMap = nMap;
    this->planeSize = planeSize;
    this->closedSet = new std::vector<Node>();
}

void aStar::FindPath(glm::vec3 startPos, glm::vec3 targetPos) {
    
    Node startNode;
    Node targetNode;
    for (Node n : nodeMap) {           //Find Nodes corresponding to Start and Target Position
        if (n.getX() == (int) startPos.x && n.getY() == (int) startPos.z) {
            startNode = n;
        } else if (n.getX() == (int) targetPos.x && n.getY() == (int) targetPos.z) {
            targetNode = n;
        }
    }
    openSet = new std::vector<Node>();
    // openSet->shrink_to_fit();
    closedSet = new std::vector<Node>();
    //closedSet->shrink_to_fit();
    startNode.setParentId(startNode.getId());
    openSet->push_back(startNode);
    
    std::cout << openSet->size() << std::endl;
    while (!openSet->empty()) {

        Node node = openSet->front();
        int savedI;
        for (int i = 1; i < openSet->size(); i++) {
            if (openSet->at(i).fCost() < node.fCost() || openSet->at(i).fCost() == node.fCost()) {
                if (openSet->at(i).getHCost() < node.getHCost()) {
                    node = openSet->at(i);
                    savedI = i;
                }
            }
        }
        
        openSet->erase(openSet->begin() + savedI);
        closedSet->push_back(node);
        
        if (node.getId() == targetNode.getId()) {
            RetracePath(startNode, targetNode);
            return;
        }
        std::vector<Node> neighbourNodes = getNeighbours(&node);
        for (Node neighbour : neighbourNodes) {
            
            if (!neighbour.isWalkable() || Contains(*closedSet, neighbour)) {
                continue;
            }
            
            
            int newMovementCost = node.getGCost() + GetDistance(node, neighbour);
            if (newMovementCost < neighbour.getGCost() || !Contains(*openSet, neighbour)) {
                neighbour.setGCost(newMovementCost);
                neighbour.setHCost(GetDistance(neighbour, targetNode));
                neighbour.fCost();
                neighbour.setParentId(node.getId());
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
    
    sortedList.push_back(nodeMap.at(node->getId() - 1));
    sortedList.push_back(nodeMap.at(node->getId() - planeSize - 1));
    sortedList.push_back(nodeMap.at(node->getId() - planeSize));
    sortedList.push_back(nodeMap.at(node->getId() - planeSize + 1));
    sortedList.push_back(nodeMap.at(node->getId() + 1));
    sortedList.push_back(nodeMap.at(node->getId() + planeSize + 1));
    sortedList.push_back(nodeMap.at(node->getId() + planeSize));
    sortedList.push_back(nodeMap.at(node->getId() + planeSize - 1));
    
    
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

void aStar::RetracePath(Node startNode, Node endNode) {
    std::vector<Node> path;
    Node currentNode = endNode;
    int cpt = 0;
    while (currentNode.getId() != startNode.getId()) {
        
        if (cpt == 0) {
            int i=0;
            for (Node n : *closedSet) {
                if (n.getId() == currentNode.getId()) {
                    currentNode = n;
                }
                i++;
            }
            cpt++;
        } else {
            int i=0;
            for (Node n:*closedSet) {
                if (n.getParentId() > 0) {
                    if (currentNode.getParentId() == n.getId()) {
                        path.push_back(currentNode);
                        currentNode = n;
                    }
                }
                i++;
            }
            path.push_back(currentNode);
        }
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

bool aStar::isPathFound(std::vector<Node *> path) {
    
    return false;
}

std::vector<Node> *aStar::getClosedSet() const {
    return closedSet;
}



