#include <iostream>
#include "linkedList.h"
#include <random>
#include "tree.h"
#include <fstream>

using namespace std;

int main()
{
    int length;

    //setting the size of the game
    
    cout<<"Welcome to Max It single player mode. The rules are: you can perfrom horizontal and vertical moves in turns. On horizontal move, it adds the taken value to your score while on vertical moves it subtracts it."<<endl;
    cout<<"Please enter the size of the grid:"<<endl;
    cin>>length;
    
    trace grid;
    trace answer;
    ofstream file;
    
    //creating the text file to write in
    file.open("record.txt",ios::app);
    
    tree* Tree = new tree(length);
    
    //setting the random value of each cell
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            int value = rand()%30-20;
            if(i==0 && j==0)
                value = 0;
            
            grid.createNode(value, i, j, -1);
            
            //creating the tree which is used to find the optimal score
            Tree->getMatrix()[i][j]=value;
            
        }
    }
    
    //using BFS of a tree to get the max score
    Tree->findOptimalScore(Tree->getRoot());
    
    //get the max and min score to calculate the challenge results
    int maxScore = Tree->getResult().max();
    int minScore = Tree->getResult().min();
    int score=0;
    
    cout<<"max: "<<maxScore<<endl;
    cout<<"min: "<<minScore<<endl;
    
    //displaying the game
    grid.display(length);
    
    int currentRow, currentColumn;
    int nextRow, nextColumn;
    bool check=true;
    int v=1;
    
    //set the starting position as (0,0)
    currentRow=0;
    currentColumn=0;
    
    //delete (0,0) from the available steps
    grid.deleteNode(0, 0);

    //check if there are still available and unvisited cells
    while(grid.checkFinished(currentRow, currentColumn, v)==true)
    {
        //input the next step
        cout<<"Please enter the next column number:";
        cin>>nextColumn;
        cout<<"Please enter the next row number:";
        cin>>nextRow;
        
        //check if the next step is visited
        if(answer.checkVisited(nextRow, nextColumn) == true)
        {
            cout<<"It has already been visited. "<<endl;
            continue;
        }

        //check if the user input is (0,0) which is not acceptable
       if(nextRow==0 && nextColumn == 0)
        {
            cout<<"It's not a valid attempt."<<endl;
            continue;
        }
        
        //check if the direction should be vertical
        if(v==1)
        {
            if(currentRow==nextRow)
            {
                //deleting the node from the available steps
                int value = grid.deleteNode(nextRow, nextColumn);
                //putting the same node into the answer linked list
                answer.createNode(value, nextRow, nextColumn,nextColumn);
                
                currentRow = nextRow;
                currentColumn = nextColumn;
                check = true;
                //calculating the score
                score = score + value;
            }
            else
            {
                cout<<"This number is not in the same row";
                check = false;
            }

        }
        
        //check if the direction should be horizontal
        if(v==-1)
        {
            if(currentColumn==nextColumn)
            {
                //deleting the node from the available steps
                int value = grid.deleteNode(nextRow, nextColumn);
                //putting the same node into the answer linked list
                answer.createNode(value, nextRow, nextColumn,nextRow);
                
                currentRow = nextRow;
                currentColumn = nextColumn;
                check = true;
                //calculating the score
                score = score - value;
            }
            else
            {
                cout<<"This number is not in the same column";
                check = false;
            }


        }
        
        //changing the direction to opposite after eaach round
        if(check == true)
            v=0-v;
    
    }
    
    //displaying the answer
    answer.displayAnswer();
    //showing the score
    cout<<"your score: "<<score<<endl;
    
    double finalScore = ((double)score - (double)minScore)/((double)maxScore - (double)minScore);
    //showing the final score using the formula
    cout<<"Your final score: "<<finalScore<<endl;
    //writing the score into the text file
    file<<"score: "<<finalScore<<endl;    
    file.close();
    
    return 0;
}
