//
// Created by ssohy on 12/14/2019.
//

#ifndef RUSTBUCKETS_NODE_H
#define RUSTBUCKETS_NODE_H


class Node {

private:
    int x,y;
    int fCost,gCost,hCost;
    bool walkable;
public:
    bool isWalkable() const;
    
    void setWalkable(bool walkable);


public:
    Node(int x,int y);
    

    int getX() const;
    
    void setX(int x);
    
    int getY() const;
    
    void setY(int y);
    
    int getFCost() const;
    
    void setFCost(int fCost);
    
    int getGCost() const;
    
    void setGCost(int gCost);
    
    int getHCost() const;
    
    void setHCost(int hCost);
};


#endif //RUSTBUCKETS_NODE_H
