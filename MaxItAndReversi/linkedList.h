#ifndef linkedList_h
#define linkedList_h

#include <iostream>

using namespace std;

struct node
{
    int value;
    int index;
    int column, row;
    node *next;
};

class trace
{
private:
    //set the node head and tail
    node *head, *tail;
public:
    trace()
    {
        //set the default head and tail to null
        head = NULL;
        tail = NULL;
    }
    
    void createNode(int value, int row, int column, int index)
    {
        node *temp = new node;
        temp->value = value;
        temp->row = row;
        temp->column = column;
        temp->index = index;
        temp->next = NULL;
        
        //check if the new node is inserted to an empty list
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    
    //function to display the game grid
    void display(int size)
    {
        node *temp = new node;
        temp = head;
        
        while(temp!=NULL)
        {
            cout<<"---------------------------------";
            cout<<endl;

            for(int i=0; i<size; i++)
            {
                cout<<"|"<<"\t";
                for(int j=0; j<size; j++)
                {
                    cout<<temp->value<<"\t"<<"|"<<"\t";
                    temp=temp->next;
                }
                cout<<endl;
                cout<<"---------------------------------";
                cout<<endl;
            }
        }
    }
    //fuction to delete specific node according to its row and column
    int deleteNode(int row, int column)
    {
        node *current = new node;
        node *previous = new node;
        
        current = head;
        if(head->row==row && head->column==column)
        {
            int value = head->value;
            head=head->next;
            return value;
        }
        else
        {
            while(current!=NULL)
            {
                previous = current;
                current = current->next;
                
                if(current->row == row && current->column == column)
                {
                    previous->next = current->next;
                    
                    return current->value;
                }
                
                
            }
        }
 
        return -100;
    }
    
    bool emptyList()
    {
        if(head==NULL)
            return true;
        else return false;
    }
    
    void displayAnswer()
    {
        node *temp = new node;
        temp = head;

        while(temp!=NULL)
        {
            cout<<temp->index<<"\t";
            temp=temp->next;
        }
    }
    
    bool checkFinished(int row, int column, int v)
    {
        node *current = new node;
        current = head;
        if(v==1)
        {
            while(current!=NULL)
            {
                if(current->row == row)
                {
                    return true;
                }
                
                current=current->next;
            }
            return false;
        }
        
        if(v==-1)
        {
            while(current!=NULL)
            {
                if(current->column == column)
                {
                    return true;
                }
                
                current=current->next;
            }
            return false;
            
        }
        return false;
    }
    
    bool checkVisited(int row, int column)
    {
        node *current = new node;
        current = head;
        while(current!=NULL)
        {
            if(current->row == row && current->column == column)
            {
                return true;
            }
            
            current=current->next;
        }
        return false;

    }

};


#endif /* linkedList_h */
