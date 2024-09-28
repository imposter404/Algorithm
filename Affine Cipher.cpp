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



int Mod(int x,int y)
{
    return (x % y + y) % y; 
}


void String::Decrypt(){
    int a_inv;
    for(int i=0;i<26;i++)
    {
        if((a*i)%26==1)
        {
            a_inv=i;
            break;
        }
    }

    for(int i=0;i<encrypt.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(l[j]==encrypt[i])
            {
                // decrypt+=l[(23*(j-b))%26];    //this will not word due to compiler issue
                // cout<<(23*(5-20))%26;        //output : -7   should be: 19   due to -ve number :(
                // cout<<Mod(-11,5); 				// real mod operatior function :)
                decrypt+=l[Mod((23*(j-b)),26)];
                
            }
        }
    }
}



int main(){
	String S;
    S.str="TWENTY";
    S.a=17;
    S.b=20;
    cout<<"String : "<<S.str;
   cout<<"\nA : "<<S.a;
   cout<<"\nB : "<<S.b;
    S.Encrypt();
    cout<<"\nEncrypt : "<<S.encrypt;
    S.Decrypt();
    cout<<"\nDecrypt : "<<S.decrypt;
	return 0;
}
