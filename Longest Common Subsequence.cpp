#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Matrix{
	public :
			int **matrix;
			int size=0;
			string x;
			string y;
            stack <int> sta;
            void values();
			void LCS();
			void display();
};

void Matrix::values(){
    matrix=new int*[x.length()+1];
    for(int i=0;i<=x.length();i++)
	{
		matrix[i]=new int[y.length()+1];
	}
    for(int i=0;i<=x.length();i++)
	{
		for(int j=0;j<=y.length();j++)
		{
			matrix[i][j]=0;
			matrix[i][j]=0;
		}
	}	
}


