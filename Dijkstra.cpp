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