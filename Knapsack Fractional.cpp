#include<iostream>
#include<string>
using namespace std;

class Matrix{
	public :
			float **matrix;
			int x_size;
			int n;
			int profit;
     void Values(int values[6][3]);
			void knapsack();
			void display();
};

void Matrix::Values(int values[6][3]){
    matrix=new float*[x_size];
    for(int i=0;i<x_size;i++)
	{
		matrix[i]=new float[4]; // {item,weight,profit,pi/wi}
        for(int j=0;j<3;j++)
        {
            matrix[i][j]=values[i][j];
        }
         matrix[i][3]=matrix[i][2]/matrix[i][1];
	}
}

void Matrix::knapsack(){
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<x_size-1;j++)
        {
            if(matrix[j][3] < matrix[j+1][3])
            {
                    swap(matrix[j],matrix[j+1]);
            }
        }
    }
}


void Matrix::display(){
	
	for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<4;j++)
        {
			cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
	
    
	int i=0;
	cout<<"\nItem : ";
	while(n!=0)
	{
		if((n-matrix[i][1])>=0)
		{
			n-=matrix[i][1];
			profit+=matrix[i][2];	
		}
		else{
			profit+=(n/matrix[i][1])*matrix[i][2];
			n=0;
		}
		cout<<matrix[i][0]<<" ";
		i++;
	}
	cout<<"\nProfit : "<<profit;
}
