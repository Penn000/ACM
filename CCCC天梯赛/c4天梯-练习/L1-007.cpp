//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string str[20] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	string n;
	while(cin>>n)
	{
		for(int i = 0; i < n.length(); i++){
			if(i == n.length()-1)cout<<(n[i]=='-'?"fu":str[n[i]-'0'])<<endl;
			else cout<<(n[i]=='-'?"fu":str[n[i]-'0'])<<" ";
		}
	}

    return 0;
}
