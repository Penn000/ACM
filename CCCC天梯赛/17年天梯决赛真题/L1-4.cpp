#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string str;
	cin>>n;
	int cnt = 0;
	while(cin>>str){
		if(str[0] == 'E')break;
		if(cnt == n){cout<<str<<endl;cnt =0 ;}
		else{
			if(str[0] == 'C')cout<<"Bu"<<endl;
			else if(str[0] == 'J')cout<<"ChuiZi"<<endl;
			else if(str[0] == 'B')cout<<"JianDao"<<endl;
			cnt++;
		}
	}

	return 0;
}
