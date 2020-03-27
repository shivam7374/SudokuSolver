#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canweplace( int arr[][9],int i,int j,int n, int num)
{

		for(int h=0;h<9;h++)
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

		for(int u = sx;u<sx+3;u++)
		{
			for(int v=sy;v<sy+3;v++)
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
{
	int mat[9][9]={
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
	sudokusolver(mat,0,0,9);
	return 0;
}