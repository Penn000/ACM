//2018-03-15
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100005;
int fa[N], dd_id[N], dd_bs[N], depth[N];

int getDepth(int x){
	if(fa[x] == x)return 0;
	if(depth[x])return depth[x];
	return depth[x] = getDepth(fa[x])+1;
}

int main()
{
	int n, k;
	double Z, r;
	while(cin>>n>>Z>>r){
		r = (100-r)/100;
		int cnt = 0, tmp;
		memset(depth, 0, sizeof(depth));
		for(int i = 0; i < n; i++)
		  	fa[i] = i;
		for(int i = 0; i < n; i++){
			cin >> k;
			if(!k){
				cin>>tmp;
				dd_id[cnt] = i;
				dd_bs[cnt++] = tmp;
			}else{
				while(k--){
					cin>>tmp;
					fa[tmp] = i;
				}
			}
		}
		double sum = 0;
		for(int i = 0; i < cnt; i++){
			double dsum = Z*dd_bs[i];
			int dp = getDepth(dd_id[i]);
			dsum *= pow(r, dp);
			sum += dsum;
		}
		cout<<(int)sum<<endl;
	}

	return 0;
}
