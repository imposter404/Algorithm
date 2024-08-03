#include<string>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
#define n 99



class Matrix{
	public :
		int edge=0;
		int sum=0;
		int v=7;
		int prims(int matrix[7][7],int start);
};




int Matrix::prims(int matrix[7][7],int start){
	int arr[7]={0,0,0,0,0,0,0};
	arr[start]=1;
	while(edge!=v-1)
	{	
		int min=n;
		int ptr_j;
		for(int i=0;i<v;i++)
		{
			if(arr[i]==0)
			{
				continue;
			}
			else{
				for(int j=0;j<v;j++)
				{
					if(matrix[i][j]<min && matrix[i][j]>0 && arr[j]!=1)
					{
						min=matrix[i][j];
						ptr_j=j;
					}
				}
			}
		}
		arr[ptr_j]=1;
		sum+=min;
		edge++;
		cout<<"min= "<<min;
	}
	
	
	
	
return sum;
}









int main(){
	cout<<"start";
	int start;
	cin>>start;
	Matrix M;
	int matrix[7][7]={
// j 0	  1    2	3	 4
	{0  , 2  , 2  , 0  , 0 , 0 , 0},
	{2  , 0  , 1  , 2  , 4 , 0 , 0},
	{2  , 1  , 0  , 3  , 0 , 4 , 0},
	{0  , 2  , 3  , 0  , 2 , 3 , 0},
	{0  , 4  , 0  , 2  , 0 , 2 , 3},
	{0  , 0  , 4  , 3  , 2 , 0 , 3},
	{0  , 0  , 0  , 0  , 3 , 3 , 0}
	};
	M.prims(matrix,start);
	cout<<"sum ="<<M.sum;





return 0;
}

