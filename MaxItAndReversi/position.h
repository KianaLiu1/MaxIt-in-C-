#ifndef treeNode_h
#define treeNode_h

class position
{
    int row;
    int column;
    
    //set the row and column of a cell
    void createPosition(int a, int b)
    {
        row=a;
        column=b;
    }
    
    //constructive function to set the default as (-1,-1)
    position()
    {
        row=-1;
        column=-1;
    }
    
    //set the row and get the row
    void setRow(int a)
    {
        row=a;
    }
    int getRow()
    {
        return row;
    }
    //set the column and get the column
    void setColumn(int b)
    {
        column = b;
    }
    int getColumn()
    {
        return column;
    }
};


#endif /* treeNode_h */
