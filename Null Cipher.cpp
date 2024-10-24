#include<iostream>
#include<string>
using namespace std;

class String{
	public :
		string str;
		string decrypt;
        string l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		void Encrypt();
		void Decrypt();
};


int Mod(int x,int y)
{
    return (x % y + y) % y; 
}


void String::Decrypt(){
int flag=0;
flag=1;
for(int i=0;i<str.length();i++)
{
    if(flag==1)
    {
        decrypt+=str[i];
        flag=0;
    }
    if(str[i]==' ')
    {
        flag=1;
    }

}
}



int main(){
    String S;
    S.str="News Eight Weather: Tonight increasing snow. Unexpected precipitation smothers eastern towns. Be extremely cautious and use snowtires especially heading east. The highway is not knowingly slippery. Highway evacuation is suspected. Police report emergency situations in downtown ending near Tuesday";
    cout<<"String : "<<S.str;
    S.Decrypt();
    cout<<"\n";
    cout<<"\nDecrypt : "<<S.decrypt;
	return 0;
}
