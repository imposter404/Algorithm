#include <graphics.h>
#include <iostream>
#include<stack>
#include<string>
using namespace std;

class cla{
	public:
	int ptr=0;
	char arr[4];
	int weight[4];
	void values(char ch, int n);
    int sort();
};

class Tree{
	public:
		int data;
		Tree *left,*right;
		Tree(int n){
			data=n;
			left=NULL;
			right=NULL;
		}
};

Tree * createTree(char arr[],int weight[],Tree* root)
{
	stack<Tree*> sta;
	for(int i=1;i<4;i++){
		if(sta.empty())
		{
			Tree * new_node1 = new Tree (weight[0]);
			Tree * new_node2 = new Tree (weight[1]);
			Tree * root1 = new Tree (new_node1->data + new_node2->data);
			root1->left=new_node1;
			root1->right=new_node2;
  			sta.push(root1);
		}	
		else{
			Tree * new_node1 = sta.top();	
			Tree * new_node2 = new Tree (weight[i]);
			Tree * root1 = new Tree (new_node1->data + new_node2->data);
	
  		if(new_node1->data < new_node2->data)
  		{
  			root1->left=new_node1;
			root1->right=new_node2;
		}
		else
		{
			root1->left=new_node2;
			root1->right=new_node1;
		}
  		sta.push(root1);
		}
	}
	return sta.top();
}

int search(int n,int weight[],Tree* root)
{

	while(root->data!=n)
	{
		for(int i=0;i<4;i++)
		{
			if(root->left->data == n)
			{
				cout<<"0";
				root=root->left;
				break;
			}
			else if(root->right->data == n)
			{
				cout<<"1";
				root=root->right;
				break;
			}
			else if(root->left->data == weight[i])
			{
				cout<<"1";
				root=root->right;
				break;       
			}
			else if(root->right->data == weight[i] )
			{
				cout<<"0";
				root=root->left;
				break;
			}
		}
	}
}


void enco(char arr[],int weight[],Tree* root){
	for(int i=0;i<4;i++)
	{
		cout<<arr[i]<<" = ";
		search(weight[i],weight,root);
		cout<<"\n";
	}
}


void cla::values(char ch, int n){
    arr[ptr]=ch;
    weight[ptr]=n;
    ptr++;
}

int cla::sort(){
    int size= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(weight[j]>weight[j+1])
            {
                swap(weight[j],weight[j+1]);
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){

    cla c;
    c.values('A',5);
    c.values('B',1);
    c.values('C',6);
    c.values('D',3);
    c.sort();
    
    cout<<"weight"<<"   "<<"char";
    for(int i=0;i<4;i++)
    {
        cout<<"\n"<<c.weight[i]<<"        "<<c.arr[i];
    }
    
    cout<<"\n" ;
    cout<<"\n" ;
   	Tree *root;
	Tree * Root_Top=createTree(c.arr,c.weight,root);
	enco(c.arr,c.weight,Root_Top);
	return 0;
}

// why the fuck its not working 
// a fucking error on pointer
// fuck my life 
// plz fucking work :|

// // its fucking working
// tested
// :)
