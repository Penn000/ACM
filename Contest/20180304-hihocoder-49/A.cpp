#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const char Hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int transform(char ch){
	if(ch >= '0' && ch <= '9')return ch-'0';
	if(ch >= 'a' && ch <= 'f')return ch-'a'+10;
}

int main()
{
	string str;
	while(cin>>str){
		int a = 16*transform(str[1])+transform(str[2]);
		int b = 16*transform(str[3])+transform(str[4]);
		int c = 16*transform(str[5])+transform(str[6]);
		int aa = a / 17;
		if(a-17*aa > 17*aa+17-a)aa += 1;
		int bb = b / 17;
		if(b-17*bb > 17*bb+17-b)bb += 1;
		int cc = c / 17;
		if(c-17*cc > 17*cc+17-c)cc += 1;
		if(aa>=16)aa = 15;
		if(bb >= 16) bb = 15;
		if(cc >= 16) cc = 15;
		cout<<"#"<<Hex[aa]<<Hex[bb]<<Hex[cc]<<endl;
	}

	return 0;
}
