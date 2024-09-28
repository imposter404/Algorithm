#include<iostream>
#include<string>

class String{
	public :
			string str;
			string encrypt;
			string decrypt;
			int key;
                  string x="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			void Encrypt();
			void Decrypt();
};

void String::Encrypt(){
    for(int i=0;i<str.length();i++)
    {
        for(int
		 j=0;j<26;j++)
        {
            if(x[j]==toupper(str[i])){
                encrypt+=x[(j+key)%26];
            }
        }
    }
}

int Mod(int x,int y)
{
    return (x % y + y) % y; 
}