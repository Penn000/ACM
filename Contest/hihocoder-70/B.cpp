// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main()
{
	cin>>str;
	int len = str.length();
	int zero = 0, one = 0;
	for(int i = 0; i < len; i++)
	  if(str[i] == '0')zero++;
	  else one++;
	cout<<min(zero, one)<<endl;

	return 0;
}
