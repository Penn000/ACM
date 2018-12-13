// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string str;

bool check(int p){
	if(str[p] == str[p+1])return true;
	else return false;
}

int main()
{
	while(cin>>str){
		int len = str.length();
		bool ok = false;
		for(int ptr = 0; ptr < len-1; ptr++)
			if(check(ptr)){
				cout<<"YES"<<endl;
				ok = true;
				break;
			}
		if(!ok)cout<<"NO"<<endl;
	}

	return 0;
}
