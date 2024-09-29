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