#include<iostream>
#include<string>
using namespace std;

class String{
	public :
		string str;
		string encrypt;
		string decrypt;
		string key;
		void Encrypt();
		void Decrypt();
};

void String::Encrypt(){
    for(int i=0;i<str.length();i++)
    {
        encrypt+=char(((int(toupper(str[i]))-int('A')) + (int(toupper(key[i%key.length()]))-int('A')))%26+int('A'));
        // hell yeah i managed to do all the things in one line :)
        // with O(n) :)
    }
}

int Mod(int x,int y)
{
    return (x % y + y) % y; 
}


void String::Decrypt(){
    for(int i=0;i<encrypt.length();i++)
    {
        decrypt+=char(Mod((int(encrypt[i])-int('A')) - Mod((int(toupper(key[i%key.length()]))-int('A')),26),26))+int('A');
        // hell yeah i manage to decrypt also :)
        // with O(n) :)
    }
}


int main(){
    String S;
    S.str="GEEKSFORGEEKS";
    S.key="AYUSH";
    cout<<"String : "<<S.str;
    cout<<"\nKey : "<<S.key;
    S.Encrypt();
    cout<<"\nEncrypt : "<<S.encrypt;
    S.Decrypt();
    cout<<"\nDecrypt : "<<S.decrypt;
    return 0;
}
