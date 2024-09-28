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

void String::Decrypt(){
    for(int i=0;i<encrypt.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(x[j]==encrypt[i]){
                // decrypt+=x[(j-key)%26];       // this may not work due to compiler isuse with -ve number
                decrypt+=x[Mod((j-key),26)];    // real mod operatior function :)
            }
        }
    }
}


int main(){
	String S;
    S.str="ACADY";
    S.key=3;
    cout<<"String : "<<S.str;
    cout<<"\nKey : "<<S.key;
    S.Encrypt();
    cout<<"\nEncrypt : "<<S.encrypt;
    S.Decrypt();
    cout<<"\nDecrypt : "<<S.decrypt;
	return 0;
}
