//
// Created by ssohy on 12/14/2019.
//

#ifndef RUSTBUCKETS_NODE_H
#define RUSTBUCKETS_NODE_H


class Node {

private:
    int x,y;
    int gCost,hCost;
    bool walkable;
    int id;
    int parentId;
public:

    bool isWalkable() const;
    
    void setWalkable(bool walkable);

    int fCost();
    
    
    int getParentId() const;
    
    void setParentId(int parentId);
    
    Node();
    Node(int x,int y);
    
    int getId() const;
    
    void setId(int id);
    
    int getX() const;
    
    void setX(int x);
    
    int getY() const;
    
    void setY(int y);
    
    int getGCost() const;
    
    void setGCost(int gCost);
    
    int getHCost() const;
    
    void setHCost(int hCost);

};


#endif //RUSTBUCKETS_NODE_H
