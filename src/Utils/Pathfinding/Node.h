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
    static Node* parent;
public:
    bool isWalkable() const;
    
    void setWalkable(bool walkable);

    int fCost();
    
    

    
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
    
    static Node *getParent();
    
    static void setParent(Node *parent);
};


#endif //RUSTBUCKETS_NODE_H
