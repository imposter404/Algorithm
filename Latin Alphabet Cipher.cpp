#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class String{
	public :
		string str;
		string encrypt;
		string decrypt;
        string l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		void Encrypt();
		void Decrypt();
};


void String::Encrypt(){
    for(int i=0;i<str.length();i++)
    {
        ostringstream str1;
        for(int j=0;j<26;j++)
        {
            if(l[j]==toupper(str[i])){
                str1<<j; // encrypt+=to_string(j);  to_string not working in my compiler need c++11 
                break;
            }
        }
        encrypt+=str1.str()+" ";
    }
}



int Mod(int x,int y)
{
    return (x % y + y) % y; 
}


void String::Decrypt(){
    string t;
    for(int i=0;i<encrypt.length();i++)
    {
        if(encrypt[i] ==' ')
        {
            stringstream geek;
            geek<<t;
            int x=0;
            geek>>x;
            decrypt+=l[x];
    		t="";
        }
        else{
            t+=encrypt[i];
        }
    }
}



int main(){
    String S;
    S.str="HELLO";
    cout<<"String : "<<S.str;
    S.Encrypt();
    cout<<"\nEncrypt : "<<S.encrypt;
    S.Decrypt();
    cout<<"\nDecrypt : "<<S.decrypt;
	return 0;
}
