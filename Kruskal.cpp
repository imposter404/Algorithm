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
		int Kraskal(int matrix[7][7]);
};




int Matrix::Kraskal(int matrix[7][7]){

int arr[7]={0,0,0,0,0,0,0};
while(edge!=v-1)
{
	int min=n;
	int ptr_i,ptr_j;
	for(int i=0;i<v;i++)
	{
		for(int j=i;j<v;j++)
		{
			if(matrix[i][j]<min && matrix[i][j] != 0)
			{
				if(arr[i] ==1 && arr[j] ==1)
				{
					continue;
				}
				else{
					min=matrix[i][j];
					ptr_i=i;
					ptr_j=j;				
				}
			}
		}
	}	
	sum=sum+min;
	arr[ptr_i]=1;
	cout<<"\n"<<ptr_i+1<<"<->"<<ptr_j+1<<"   "<<min;
	arr[ptr_j]=1;
	edge++;
}

return sum;
}



int main(){
	cout<<"start";
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
	M.Kraskal(matrix);
	cout<<"\n sum ="<<M.sum;
return 0;
}

// kraskal done
// not verified by jdb sir 
// working
