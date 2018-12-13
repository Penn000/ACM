#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

struct Node{
	int att, def;
}troop[N], e_troop[N];

bool cmp_ack(Node a, Node b){
	if(a.att == b.att)
	  return a.def > b.def;
	return a.att > b.att;
}

bool cmp_def(Node a, Node b){
	if(a.def == b.def)
	  return a.att > b.att;
	return a.def > b.def;
}

int n, m;

int bsearch(int val){
	int l = 0, r = n-1, mid;
	while(l < r){
		mid = (l+r)>>1;
		if(troop[mid].att >= val)
		  r = mid;
		else l = mid+1;
	}
	return r;
}

int main()
{
	int T, kase = 0, ans;
	bool vis[N];
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i = 0; i < n; i++)
		  cin>>troop[i].att>>troop[i].def;
		for(int i = 0; i < m; i++)
		  cin>>e_troop[i].att>>e_troop[i].def;
		cout<<"*******************"<<endl;
		if(n < m){
			ans = -1;
		}else{
			sort(troop, troop+n, cmp);
			//for(int i = 0; i < n; i++)
			//  cout<<troop[i].att<<" "<<troop[i].def<<endl;
			//cout<<bsearch(6)<<endl;
			ans = n;
			memset(vis, 0, sizeof(vis));
			for(int i = 0; i < m; i++){
				int j = bsearch(e_troop[i].def);
				for(int i = )
			}
		}
		cout<<"Case #"<<++kase<<": "<<ans<<endl;
	}

	return 0;
}
