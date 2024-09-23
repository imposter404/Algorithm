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

void Matrix::Dijkstra(){
	weight[start][0]=0;
	weight[start][1]=start;
	for(int i=start;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if((weight[j][0]>(arr[i][j]+weight[i][0])) && arr[i][j]!=0)
			{
				weight[j][0]=arr[i][j]+weight[i][0];
				weight[j][1]=i;
			}
		}
	}

	int min=0;
	for(int i=0;i<size;i++)
	{
		cout<<"weight "<<weight[i][0]<<" "<<letter[weight[i][1]]<<"->"<<letter[i]<<"\n";
		min+=weight[i][0];
	}
	cout<<"Min "<<min;
}

int main(){
	Matrix M;
	M.size=6;
	cout<<"Start ";
	cin>>M.start;
	int values[6][6]={
	{0,4,4,0,0,0},
	{4,0,2,0,0,0},
	{4,2,0,3,6,1},
	{0,0,3,0,2,0},
	{0,0,6,2,0,3},
	{0,0,1,0,3,0}
	};
	M.Values(values);
	M.Dijkstra();
	return 0;
}