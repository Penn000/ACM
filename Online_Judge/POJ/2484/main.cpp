//2017-10-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while(cin>>n && n){
		if(n <= 2)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}

	return 0;
}
