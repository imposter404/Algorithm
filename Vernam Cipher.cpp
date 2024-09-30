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
