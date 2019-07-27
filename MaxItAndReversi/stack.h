
#ifndef stack_h
#define stack_h
#define MAX 100000

#include <iostream>

using namespace std;

class stack
{
private:
    int CurrentCell;
    int array[MAX];
public:
    //defining the functions of stack
    void CreateStack();
    void PushStack(int a);
    int PopStack();
    bool FullStack();
    bool EmptyStack();
    void PrintStack();
    int peak();
    int max();
    int min();
    
};

void stack::CreateStack()
{
    CurrentCell = -1;
}

void stack::PushStack(int a)
{
    //insert a cell to the end of the stack
    CurrentCell++;
    array[CurrentCell]=a;
    
}
int stack::PopStack()
{
    //delete a cell from the end of the stack
    int c = array[CurrentCell];
    CurrentCell--;
    return c;
}

bool stack::FullStack()
{
    //check if the stack has reached its limit
    if(CurrentCell == MAX-1)
    {
        return true;
    }
    else return false;
}

bool stack::EmptyStack()
{
    //check if the stack is empty
    if(CurrentCell == -1)
    {
        return true;
    }
    else return false;
}

void stack::PrintStack()
{
    cout<<"Print stack"<<endl;
    for(int i=0; i<=CurrentCell;i++)
    {
        cout<<array[i]<<endl;
    }
}

//check the top of the stack
int stack::peak()
{
    int c = array[CurrentCell];
    return c;
}

//check the max number of a stack
int stack::max()
{
    int max;
    if(CurrentCell==0)
        return array[0];
    
    max = array[0];
    
    for(int i=1; i<=CurrentCell; i++)
    {
        if(array[i]>max)
            max=array[i];
    }
    return max;
}

//check the min number of a stack
int stack::min()
{
    int min;
    if(CurrentCell ==0)
        return array[0];
    
    min = array[0];
    
    for(int i=1; i<=CurrentCell; i++)
    {
        if(array[i]<min)
            min = array[i];
    }
    return min;
}


#endif /* stack_h */

