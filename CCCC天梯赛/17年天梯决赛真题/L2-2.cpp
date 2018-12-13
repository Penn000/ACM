#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int val[1000005], nex[1000005], order[1000005];

int main()
{
	int n, head, a, b, c;
	while(cin>>head>>n){
		for(int i = 0; i < n; i++){
			cin>>a>>b>>c;
			val[a] = b;
			nex[a] = c;
		}
		int p = head;
		int cnt = 1;
		order[cnt] = p;
		p = nex[p];
		while(p != -1){
			cnt++;
			order[cnt] = p;
			p = nex[p];
		}
		for(int i = 1; i <= cnt; i++){
			if(i&1){
				int add = order[n-i/2];
				if(i == cnt)
					printf("%05d %d -1\n", add, val[add]);
				else
					printf("%05d %d %05d\n", add, val[add], order[(i+1)/2]);
			}else{
				int add = order[i/2];
				if(i == cnt)
					printf("%05d %d -1\n", add, val[add]);
				else
					printf("%05d %d %05d\n", add, val[add], order[n-i/2]);
			}
		}
	}

	return 0;
}
