// 2018-06-30
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n, type, u;
		scanf("%d", &n);
		while(!pq.empty())pq.pop();
		while(n--){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d", &u);
				pq.push(u);
			}else if(type == 2){
				cout<<pq.top()<<endl;
				pq.pop();
			}
		}
	}

	return 0;
}
