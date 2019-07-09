#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

string add(string s1, string s2) {
	int len1 = s1.size(), len2 = s2.size();
	vector<char> vec;
	int c = 0;
	for(int i = 0; i < max(len1, len2); i++) {
		int a1, a2;
		if(i >= len1) a1 = 0;
		else a1 = s1[len1-i-1] - '0';
		if(i >= len2) a2 = 0;
		else a2 = s2[len2-i-1] - '0';
		int tmp = c + a1 + a2;
		vec.push_back(tmp % 10 + '0');
		c = tmp / 10;
	}
	if(c) vec.push_back(c+'0');
	string ans(vec.size(), '0');
	for(int i = 0; i < vec.size(); i++) {
		ans[i] = vec[vec.size()-i-1];
	}
	return ans;
}

string F[1010];
void init(){
	F[1] = "1";
	F[2] = "1";
	for(int i = 3; i < 1005; i++) {
		F[i] = add(F[i-1], F[i-2]);
	}
}

int main()
{
	init();
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<F[n]<<endl;
	}

	return 0;
}
