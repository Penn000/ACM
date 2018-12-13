#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1500000;

int arr[N], book[N], book2[N];
int fg[N];

int main()
{
	freopen("input1007.txt", "r", stdin);
    int n;
	while(scanf("%d", &n) != EOF){
		memset(book, 0, sizeof(book));
		memset(book2, 0, sizeof(book2));
		memset(fg, 0, sizeof(fg));
		int ans = 0;
		for(int i = 0; i < n; i++){
		  	scanf("%d", &arr[i]);
			book[arr[i]]++;
		}
		for(int i = 1; i <= n; i++){
			int tmp = book[i]/2;
			ans += tmp;
			book[i] -= 2*tmp;
			book2[i] = book[i];
			fg[i] = tmp;
		}
		int ans2 = ans;
		for(int i = 1; i <= n; i++){
			if(book[i] && book[i+1] && book[i+2]){
				ans++;
				book[i] = book[i+1] = book[i+2] = 0;
			}
			if(!book[i] && i-2>=1 && book[i-1] && book[i-2] && book[i+1] && book[i+2] && fg[i]){
				ans++;
				book[i-1] = book[i-2] = book[i+1] = book[i+2] = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			if(i-2>=1 && book2[i-2]==1&&book2[i-1]==1&&!book2[i]&&book2[i+1]==1&&!book2[i+2]&&fg[i+2]&&book2[i+3]==1&&book2[i+4]==1){
				ans2--;
				fg[i]--;
				book2[i] += 2;
			}
			if(i-2>=1 && book2[i-2]==2&&book2[i-1]==1&&!book2[i]&&book2[i+1]==1&&((!book2[i+2]&&fg[i+2]) || book2[i+2]==1)){
				ans2--;
				fg[i]--;
				book2[i] += 2;
			}
		}
		for(int i = 1; i <= n; i++){
			if(book2[i] && book2[i+1] && book2[i+2]){
				ans2++;
				book2[i]--; book2[i+1]--; book2[i+2]--;
			}
		}
		printf("%d\n", max(ans,ans2));
	}

	return 0;
}
