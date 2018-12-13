//2017-09-19
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

int a[N], n;
int _next[N], _pre[N];
int head, tail, que[N<<1];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		tail = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			_next[i] = i+1;
			_pre[i] = i-1;
			que[tail++] = i;
		}
		a[0] = 0;
		a[n+1] = N;
		_pre[0] = 0;
		_next[0] = 1;
		_pre[n+1] = N;
		_next[n+1] = n+1;
		int ans = n, fg = 1, ptr;
		while(fg){
			fg = 0;
			head = 0;
			ptr = 0;
			while(head < tail){
				int cnt = 0, i = que[head];
				for(; i <= n; i = _next[i]){
					if(a[i] > a[_next[i]]){
						cnt++;
						fg = 1;
					}else break;
				}
				if(cnt){
					ans -= cnt+1;
					_next[_pre[que[head]]] = _next[i];
					_pre[_next[i]] = _pre[que[head]];
					que[ptr++] = _pre[que[head]];
				};
				while(que[head] <= i && head < tail)head++;
			}
			tail = ptr;
		}
		if(ans < 0)ans = 0;
		printf("%d\n", ans);
		for(int i = _next[0]; i <= n; i = _next[i]){
			if(_next[i] != N)printf("%d ", a[i]);
		}
		printf("\n");
	}

	return 0;
}
