#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while(cin>>n){
		double h, w;
		while(n--){
			cin>>h>>w;
			double std_w = (h-100)*0.9;
			w /= 2;
			if(w-std_w <= -std_w*0.1)cout<<"You are tai shou le!"<<endl;
			else if(w-std_w >= std_w*0.1) cout<<"You are tai pang le!"<<endl;
			else cout<<"You are wan mei!"<<endl;
		}
	}

	return 0;
}
