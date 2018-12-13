//2017-08-31
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100000;
int arr[N], n;
bool book[N];

int main()
{
	//freopen("input1007.txt", "r", stdin);
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		sort(arr, arr+n);
		memset(book, 0, sizeof(book));
		int ans = 0;
		for(int i = 1; i < n; i++){
			if(i >= 2){
				int p1 = -1, p2 = -1;
				for(int j = i-1; j >= 0; j--){
					if(arr[j] == arr[i]-1 && !book[j]){
						p1 = j;
					}
					if(arr[j] == arr[i]-2 && !book[j]){
						p2 = j;
						break;
					}
					if(arr[j] < arr[i]-1)break;
				}
				if(p1 != -1 && p2 != -1){
					ans++;
					book[i] = book[p1] = book[p2] = 1;
				}
			}
			if(arr[i-1] == arr[i] && !book[i-1] && !book[i]){
				ans++;
				book[i-1] = book[i] = 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
