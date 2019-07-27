#ifndef treeNode_h
#define treeNode_h
#include <vector>
#include <iostream>

using namespace std;

class position
{
private:
    int row;
    int column;
    
public:
    void createPosition(int a, int b)
    {
        row=a;
        column=b;
    }
    
    position()
    {
        row=-1;
        column=-1;
    }
    
    void setRow(int a)
    {
        row=a;
    }
    int getRow()
    {
        return row;
    }
    
    void setColumn(int b)
    {
        column = b;
    }
    int getColumn()
    {
        return column;
    }
};


class treeNode
{
private:
    treeNode *parent;
    vector<treeNode*> children;
    
    position *currentPosition;
    
    int score;
    int value;
    
    bool direction;
    
public:
    treeNode()
    {
        currentPosition = new position;
    }
    void setParent(treeNode *a)
    {
        parent = a;
    }
    treeNode* getParent()
    {
        return parent;
    }
    
    void setPosition(position *current)
    {
        currentPosition->setRow(current->getRow());
        currentPosition->setColumn(current->getColumn());
    }
    
    position* getPosition()
    {
        return currentPosition;
    }
    
    int getRow()
    {
        return currentPosition->getRow();
    }
    int getColumn()
    {
        return currentPosition->getColumn();
    }
    
    void addChild(treeNode* b)
    {
        children.push_back(b);
        b->setParent(this);
    }
    void removeChild(position *c)
    {
        for(int i=0;i<children.size();i++)
        {
            if(children[i]->currentPosition->getRow() == c->getRow() && children[i]->currentPosition->getColumn() == c->getColumn())
            {
                children.erase(children.begin()+i);
            }
        }
    }
    
    int getChildrenNumber()
    {
        return children.size();
    }
    
    void setDirection(bool a)
    {
        direction = a;
    }
    
    bool getDirection()
    {
        return direction;
    }
    
    bool checkLeaf()
    {
        if(children.size()==0)
            return true;
        else return false;
    }
    
    void setScore(int thisScore)
    {
        score = thisScore;
    }
    
    int getScore()
    {
        return score;
    }
    
    void setValue(int value)
    {
        this->value = value;
    }
    
    int getValue()
    {
        return value;
    }
};


#endif /* treeNode_h */
