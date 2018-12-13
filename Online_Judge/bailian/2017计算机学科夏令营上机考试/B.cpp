#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool isEqual(char a, char b){
	int aa, bb;
	if(a >= 'a' && a <= 'z')
	  aa = a-'a';
	else if(a >= 'A' && a <= 'Z')
	  aa = a-'A';

	if(b >= 'a' && b <= 'z')
	  bb = b-'a';
	else if(b >= 'A' && b <= 'Z')
	  bb = b-'A';
	
	return aa == bb;
}

char litter(char x){
	if(x >= 'A' && x <= 'Z')
	  return x - 'A' + 'a';
	else
	  return x;
}

int main()
{
	string str;
	while(cin>>str){
		int cnt = 1;
		for(int i = 1; i < str.length(); i++){
			if(isEqual(str[i], str[i-1]))
			  cnt++;
			else{
				cout<<"("<<litter(str[i-1])<<","<<cnt<<")";
				cnt = 1;
			}
			if(i == str.length()-1)
				cout<<"("<<litter(str[i])<<","<<cnt<<")"<<endl;
		}
	}

	return 0;
}
