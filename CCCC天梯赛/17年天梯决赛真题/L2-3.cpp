#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
	int v, next;
}edges[600000];

int head[600], tot;

void init(){
	memset(head, -1, sizeof(head));
	tot = 0;
}

void addEdge(int u, int v){
	edges[tot].v = v;
	edges[tot].next = head[u];
	head[u] = tot++;
}

int arr[600], arr2[600], n, k;

bool OK(){
	sort(arr2+1, arr2+n+1);
	int len = unique(arr2+1, arr2+n+1)-arr2-1;
	if(len!=k)return false;
	for(int u = 1; u <= n; u++){
		for(int i = head[u]; i != -1; i = edges[i].next){
			int v = edges[i].v;
			if(arr[u] == arr[v])return false;
		}
	}
	return true;
}

int main()
{
	int m;
	while(cin>>n>>m>>k){
		init();
		int u, v;
		while(m--){
			cin>>u>>v;
			addEdge(u, v);
			addEdge(v, u);
		}
		cin>>m;
		while(m--){
			for(int i = 1; i <= n; i++){
			  cin>>arr[i];
			  arr2[i] = arr[i];
			}
			if(OK())cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}

	return 0;
}
