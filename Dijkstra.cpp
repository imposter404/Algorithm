#include<iostream>
#include<string>
using namespace std;
#define n 99

class Matrix{
	public :
			int **arr;
			int size=0;
			int **weight;
			int start;
			string letter[6]={"A","B","C","D","E","F"};

			void Values(int values[6][6]);
			void Dijkstra();
};

void Matrix::Values(int values[6][6]){
	arr=new int*[6];
	weight=new int*[6];
	int c=0;
	for(int i=0;i<size;i++)
	{
		arr[i]=new int[6];
		weight[i]=new int[2]; //weight[[sum,direction]]
		for(int j=0;j<size;j++)
		{
			arr[i][j]=values[i][j];
			weight[i][j]=n;
		}
	}
}