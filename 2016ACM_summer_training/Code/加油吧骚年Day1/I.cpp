//2018-08-12
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 150;

int x[N], y[N], info[N], n;

int color_to_id(char ch){
	if(ch == 'R')return 1;
	if(ch == 'G')return 2;
	if(ch == 'B')return 3;
	if(ch == 'Y')return 4;
	if(ch == 'W')return 5;
}

int count_one(int x){
	int cnt = 0;
	while(x){
		cnt += (x&1);
		x >>= 1;
	}
	return cnt;
}

bool check(int sta){
	for(int i = 0; i < n; i++){
		info[i] = 0;
		info[i] |= (1<<(x[i]-1))&sta;
		info[i] |= (1<<(y[i]-1+5))&sta;
		for(int j = 0; j < i; j++)
			if(info[i] == info[j] && (x[i]!=x[j] || y[i]!=y[j]))
			  	return false;
	}
	return true;
}

int main()
{
	string str;
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin>>str;
			x[i] = color_to_id(str[0]);
			y[i] = str[1]-'0';
		}
		int ans = 10;
		for(int i = 0; i < (1<<10); i++){
			int n_one = count_one(i);
			if(n_one >= ans)continue;
			if(check(i))ans = n_one;
		}
		cout<<ans<<endl;
	}

	return 0;
}
