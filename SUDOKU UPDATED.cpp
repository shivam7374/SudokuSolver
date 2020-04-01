#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canweplace( int arr[][9],int i,int j,int n, int num)
{

		for(int h=0;h<n;h++)
		{
			if(arr[i][h]==num || arr[h][j]==num)
			{
				return false;
			}
		}
	int rn=sqrt(n);
	int a=(i/rn);
	int b=(j/rn);
	int sx=a*rn;
	int sy=b*rn;

		for(int u = sx;u<sx+rn;u++)
		{
			for(int v=sy;v<sy+rn;v++)
			{
				if(arr[u][v]==num)
				{
					return false;
				}
			}
		}

		return true;


}
bool sudokusolver(int arr[][9],int i,int j,int n)
{
	if(i==n){
		for(int m=0;m<n;m++)
		{
			for(int d=0;d<n;d++)
				{
					cout<<arr[m][d]<<" ";
				}	
				cout<<endl;
		}
		return true;
	}
	if(j==n){
		 return sudokusolver(arr,i+1,0,n);
	}
	if(arr[i][j]!=0)
	{
		 return sudokusolver(arr,i,j+1,n);
	}
	
	else{
	for(int num=1;num<=n;num++)
	{
		if(canweplace(arr,i,j,n,num))
		{
			arr[i][j]=num;

			if(sudokusolver(arr,i,j+1,n))
			{
				return true;
			}
		}
	}

	arr[i][j]=0;
	return false;
}
}
int main()
{	cout<<"SUDOKU GAME "<<endl<<"Please enter the n for nXn sudoku"<<endl;
	// cout<<"Here we used a 9X9 sudoku as an example so please enter 9"<<endl;
	int n;
	cin>>n;
	/* int mat[9][9]={
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
    */
    int mat[n][n]={0};
    cout<<"Enter the elements of sudoku to be solved with blank position as 0 "<<endl;
    cout<<"Please fill the sudoku row wise"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }

    }
    cout<<endl<<"This is what you entered"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

    }
    
	sudokusolver(mat,0,0,n);
	return 0;
}