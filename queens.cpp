#include <bits/stdc++.h>
using namespace std;
#define N 4

bool safe(int board[N][N],int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		if(board[row][i])
		{
			return false;
		}
	}
	for(i=row,j=col;i>=0&&j>=0;i--,j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}
	for(i=row,j=col;i<N&&j>=0;i++,j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}
	return true;
}

bool noqueen(int board[N][N],int col)
{
	if(col>=N)
	{
		return true;
	}
	for(int i=0;i<N;i++)
	{
		if(safe(board,i,col))
		{
			board[i][col]=1;
			if(noqueen(board,col+1))
			{
				return true;
			}
			else
			{
				board[i][col]=0;	//backtracking
			}
		}
	}
	return false;
}

int main()
{
	int board[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if(noqueen(board,0)==false)
	{
		cout<<"Solution doesnt exist";
		return false;
	}
	else
	{
		for (int i = 0; i < N; i++) 
		{ 
        	for (int j = 0; j < N; j++) 
            {
            	cout<<board[i][j]<<"\t"; 
            }
            cout<<"\n";   	 
    	}
	}
	return 0;
}