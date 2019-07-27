#ifndef cell_h
#define cell_h
#include "stack.h"
#include "treeNode.h"

class tree
{
private:
    treeNode *root;
    int **matrix;
    int size;
    stack result;
public:
    //setting the default of the tree
    tree(int length)
    {
        root = new treeNode;
        root->setParent(NULL);
        root->setScore(0);
        root->setDirection(true);
        position *currentPosition = new position;
        
        currentPosition->setRow(0);
        currentPosition->setColumn(0);
        
        root->setPosition(currentPosition);
        
        matrix = new int *[length];
        size = length;
        for(int i=0; i<length; i++)
        {
            matrix[i]=new int[length];
        }
        result.CreateStack();
    }
    int ** getMatrix()
    {
        return matrix;
    }
    void printTree()
    {
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
                cout<<matrix[i][j]<<endl;
        }
    }
    treeNode* getRoot()
    {
        return root;
    }
    stack getResult()
    {
        return result;
    }
    
    
    void findOptimalScore(treeNode *);
    void findChildren(treeNode *, vector<treeNode*> &);
};

//function used to get the max score
void tree::findOptimalScore(treeNode *node)
{
    //setting a vector to contain the results
    vector<treeNode*> set;
    findChildren(node, set);
    
    if(set.size()==0)
    {
        //adding the node to the stack
        result.PushStack(node->getScore());
    }
    
    for(int i=0; i<set.size(); i++)
    {
        //create a set that contains each branch of the tree
        set[i]->setParent(node);
        set[i]->setDirection(!node->getDirection());
        if(node->getDirection()==true)
        {
            set[i]->setScore(node->getScore()+set[i]->getValue());
        }
        else
        {
            set[i]->setScore(node->getScore()-set[i]->getValue());
        }
        
        //find the final score of each branch
        findOptimalScore(set[i]);
        
    }
}

//function used to find the children of each tree node
void tree::findChildren(treeNode *node, vector<treeNode*> &children)
{
    vector<treeNode*> removedChildren;
    
    //check if the direction is horizontal or vertical
    if(node->getDirection()==true)
    {
        for(int j=0; j<size; j++)
        {
            if(j==node->getColumn())
                continue;
            treeNode* child = new treeNode;
            //set the child node data using position
            child->setValue(matrix[node->getRow()][j]);
            position* p1 = new position;
            p1->setRow(node->getRow());
            p1->setColumn(j);
            child->setPosition(p1);
            child->setParent(node);
            //push the child node to the stack
            children.push_back(child);
        }
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            if(i==node->getRow())
                continue;
            treeNode* child = new treeNode;
            child->setValue(matrix[i][node->getColumn()]);
            position* p1 = new position;
            p1->setRow(i);
            p1->setColumn(node->getColumn());
            child->setPosition(p1);
            child->setParent(node);
            children.push_back(child);
        }
    }
    
    treeNode *current = node;
    treeNode *parent = node->getParent();
    vector<position*> ancestor;
    
    while(parent!=NULL)
    {
        //push the visited cells into the ancestor stack
        ancestor.push_back(parent->getPosition());
        current = parent;
        parent = current->getParent();
    }
    //check the intersction of available children cells and visited cells
    for(int i=0; i<children.size(); i++)
    {
        for(int j=0; j<ancestor.size(); j++)
        {
            if(children[i]->getRow()==ancestor[j]->getRow() && children[i]->getColumn() == ancestor[j]->getColumn())
            {
                removedChildren.push_back(children[i]);
            }
        }
    }
    
    //remove all the visited cells from the children stack
    for(int i=0; i<removedChildren.size(); i++)
    {
        for(int j=0; j<children.size(); j++)
        {
            if(removedChildren[i]->getRow()==children[j]->getRow() && removedChildren[i]->getColumn()==children[j]->getColumn())
            {
                children.erase(children.begin()+j);
                break;
            }
        }
    }
    
    
}

#endif /* cell_h */
