//2017-09-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

int n, m;
int trie[32*N][2], value[32*N], tot;

void init(){
	tot = 1;
	memset(trie[0], 0, sizeof(trie[0]));
}

void insert(int x){
	int cur = 0;
	for(int i = 31; i >= 0; i--){
		int idx = ((x>>i)&1);
		if(!trie[cur][idx]){
			memset(trie[tot], 0, sizeof(trie[tot]));
			value[tot] = 0;
			trie[cur][idx] = tot++;
		}
		cur = trie[cur][idx];
	}
	value[cur] = x;
}

int query(int x){
	int cur = 0;
	for(int i = 31; i >= 0; i--){
		int idx = ((x>>i)&1);
		if(trie[cur][idx^1]) cur = trie[cur][idx^1];
		else cur = trie[cur][idx];
	}
	return value[cur];
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		init();
		int x;
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			insert(x);
		}
		printf("Case #%d:\n", ++kase);
		while(m--){
			scanf("%d", &x);
			printf("%d\n", query(x));
		}
	}

	return 0;
}
