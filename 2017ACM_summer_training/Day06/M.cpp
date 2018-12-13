//2017-08-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 200010;
int color[N], n, m, k, root[N], tot;
struct Node{
	int id, fa;
	bool operator<(const Node X) const{
		return fa < X.fa;
	}
}node[N];

void init(){
	for(int i = 1; i <= N; i++){
	  	node[i].fa = i;
		node[i].id = i;
	}
}

int getfa(int x){
	if(node[x].fa == x)return x;
	return node[x].fa = getfa(node[x].fa);
}

void merge(int a, int b){
	int af = getfa(a);
	int bf = getfa(b);
	if(af != bf)
	  	node[bf].fa = af;
}

int main()
{
	//freopen("inputN2.txt", "r", stdin);
	while(scanf("%d%d%d", &n, &m, &k)!=EOF){
		for(int i = 1; i <= n; i++)
		  	scanf("%d", &color[i]);
		init();
		int l, r;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &l, &r);
			merge(l, r);
		}
		for(int i = 1; i <= n; i++)
		  	getfa(i);
		sort(node+1, node+n+1);
		int ans = 0, maxcolor, cnt, ptr = 1;
		for(int i = 1; i <= n;){
			map<int, int> book;
			maxcolor = 0;
			cnt = 0;
			while(node[ptr].fa == node[i].fa){
				book[color[node[i].id]]++;
				maxcolor = max(maxcolor, book[color[node[i].id]]);
				i++;
				cnt++;
			}
			ans += cnt-maxcolor;
			ptr = i;
		}
		printf("%d\n", ans);
	}

	return 0;
}
