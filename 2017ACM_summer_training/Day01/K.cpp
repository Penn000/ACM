//2017-08-17
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;
const int M = 3000010;
//book[i]记录i是否出现过，pre[i]表示比i小的出现过的最大的数
int a[N], n, book[M], pre[M];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
		memset(book, 0, sizeof(book));
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
			book[a[i]] = 1;
		}
        sort(a, a + n);
		n = unique(a, a+n)-a;
        int ans = 0, maxinum = (a[n-1]<<1), ptr = 0;
		for(int i = 1; i <= maxinum; i++){
			pre[i] = ptr;
			if(book[i])ptr = i;
		}
        for (int i = 0; i < n; i++){
            for (int j = a[i]<<1; j <= maxinum; j+=a[i]){
				ans = max(ans, a[i]-j+pre[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
