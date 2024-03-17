/*
 * Name: Harrison Holt 
 * Date Submitted: 4-17-23
 * Lab Section: Section 5
 * Assignment Name: Lab 9 
 */

#include <iostream>
#include <vector>

using namespace std;
//checks if we can place the queen at a position or not
bool canplace(int**queenarray,int n,int col,int row)
{
    //check for the row
    for(int i=0;i<n;i++)
    {
        if(queenarray[row][i]==1)
            return false;
    }
    //check for left upper diagonal
    int j;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(queenarray[i][j]==1)
            return false;
    }
    //check for left lower diagonal
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(queenarray[i][j]==1)
            return false;
    }
    //if all conditions are met return true
    return true;
}
int findsolution(int ** queenarray,int n,int col)
{
    int row;
    int count=0;
    if(col==n)
    {

        return 1;
    }
    for(int i=0;i<n;i++)
        {
            row=i;
            if(canplace(queenarray,n,col,row)==true)
            {
                queenarray[row][col]=1; //if we can place the queen there then place it
                count+=findsolution(queenarray,n,col+1); //recursion
                queenarray[row][col]=0; //backtracking
            }
        }
        return count;
}

int nQueens(int n){


    int ** queenarray=new int *[n];
    for(int i=0;i<n;i++)
    {
        queenarray[i]= new int[n];
        for(int j=0;j<n;j++)
        {
            queenarray[i][j]=0;
        }
    }
    //helper function to return the count of distinct solutions
    return findsolution(queenarray,n,0);
}

/**
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
} */ 
