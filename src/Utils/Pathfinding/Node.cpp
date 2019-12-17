//
// Created by ssohy on 12/14/2019.
//

#include "Node.h"

int Node::getX() const {
    return x;
}

//Getter / Setter
void Node::setX(int x) {
    Node::x = x;
}

int Node::getY() const {
    return y;
}

void Node::setY(int y) {
    Node::y = y;
}

int Node::getGCost() const {
    return gCost;
}

void Node::setGCost(int gCost) {
    Node::gCost = gCost;
}

int Node::getHCost() const {
    return hCost;
}

void Node::setHCost(int hCost) {
    Node::hCost = hCost;
}

Node::Node(int x, int y) {
    setX(x);
    setY(y);
    setGCost(0);
    setHCost(0);
}

bool Node::isWalkable() const {
    return walkable;
}

void Node::setWalkable(bool walkable) {
    Node::walkable = walkable;
}

Node::Node() {

}

int Node::fCost() {
    return gCost+hCost;
}

int Node::getId() const {
    return id;
}

void Node::setId(int id) {
    Node::id = id;
}

int Node::getParentId() const {
    return parentId;
}

void Node::setParentId(int parentId) {
    Node::parentId = parentId;
}







