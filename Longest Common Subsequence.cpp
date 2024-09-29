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

void Matrix::LCS(){

for(int i=1;i<=x.length();i++)
{
    for(int j=1;j<=y.length();j++)
    {
        if(x[i-1]==y[j-1])
        {
            matrix[i][j]=matrix[i-1][j-1]+1;
        }
        else if(matrix[i][j-1] > matrix[i-1][j]){
            matrix[i][j]=matrix[i][j-1];
        }
        else{
            matrix[i][j]=matrix[i-1][j];
        }
    }
}

int i=x.length();
int j=y.length();
while(i!=1)
{
	if(matrix[i][j] == matrix[i][j-1] && matrix[i][j-1] > matrix[i-1][j] )
	{
		j--;
	}
	else if(matrix[i][j] == matrix[i-1][j] && matrix[i][j-1] <= matrix[i-1][j] )
	{
		i--;
	}
	else{
		i--;
		j--;
		sta.push(i);
	}
}


void Matrix::display()
{
	cout<<"String  : "<<x;
	cout<<"\nSub Str : "<<y;
	cout<<"\n\nLCS : ";
	while(!sta.empty())
	{
		cout<<x[sta.top()];
		sta.pop();
	}
}
