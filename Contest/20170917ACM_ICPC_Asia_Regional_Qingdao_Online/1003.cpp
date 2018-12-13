#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;
vector<string> vec;
int nex[N];

void getNext(string str, int n)
{
	nex[0] = -1;
	for(int i = 0, fail = -1; i < n;)
	{
		if(fail==-1||str[i]==str[fail])
		{
			i++, fail++;
			nex[i] = fail;
		}else fail = nex[fail];
	}
}

bool kmp(string b){
	int i = 0, j = 0;
	for(; a[i] != ""; i++, j++)
	{
		if(j != -1 && b[j] == inf)return i-j+1;
		while(j != -1 && a[i] != b[j])j = nex[j];

	}
	if(b[j] == inf)return i-j+1;
	return -1;
}

int main()
{
	int T, n, pos;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int maxinum = 0;
		string str;
		for(int i = 0; i < n; i++){
			cin>>str;
			if(maxinum < str.length()){
				maxinum = str.length();
				pos = i;
			}
			vec.push_back(str);
		}
		getNext(vec[pos], maxinum);
		for(int i = 0; i < n; i++){

		}
	}

	return 0;
}
