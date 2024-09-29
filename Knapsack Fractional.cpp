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