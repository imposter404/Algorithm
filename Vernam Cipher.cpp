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


int Mod(int x,int y)
{
    return (x % y + y) % y; 
}


void String::Encrypt(){
    for(int i=0;i<str.length();i++)
    {
        encrypt+=Mod(((int(toupper(str[i]))-int('A'))) ^ ((int(toupper(key[i]))-int('A'))) ,26) + int('A');
    }
}

void String::Decrypt(){
    for(int i=0;i<encrypt.length();i++)
    {
        decrypt+=Mod(((int(encrypt[i])-int('A'))) ^ ((int(toupper(key[i]))-int('A'))) ,26) + int('A');
    }
}


int main(){
    String S;
    S.str="RAK";
    S.key="TON";
    if(S.str.length() != S.key.length())
    {
        cout<<"Both should be of same length  "<<S.str.length()<<"!="<<S.key.length();
    }
    else{
        cout<<"String : "<<S.str;
        cout<<"\nKey : "<<S.key;
        S.Encrypt();
        cout<<"\nEncrypt : "<<S.encrypt;
        S.Decrypt();
        cout<<"\nDecrypt : "<<S.decrypt;
    }
    return 0;
}
