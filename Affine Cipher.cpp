#include<iostream>
#include<string>
#include<stack>
using namespace std;


class String{
	public :
			string str;
			string encrypt;
			string decrypt;
			int a;
			int b;
            string l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			void Encrypt();
			 void Decrypt();
};


void String::Encrypt(){
    for(int i=0;i<str.length();i++)
    {
        for(int
		 j=0;j<26;j++)
        {
            if(l[j]==toupper(str[i])){
                encrypt+=l[(a*j+b)%26];
            }
        }
    }
}