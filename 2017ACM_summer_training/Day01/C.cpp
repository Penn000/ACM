//2017-10-08
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;
int arr[N], n, m, l, ans, T;

int main(){
    int kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &l);
        arr[0] = 0;
        arr[n+1] = m;
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
		sort(arr, arr+n+1);
        ans = 0;
        int k = l;
        for(int i = 1; i <= n+1; i++){
			int a = (arr[i]-arr[i-1])%(l+1);
			int b = (arr[i]-arr[i-1])/(l+1);
			if(a+k >= l+1){
				k = a;
				ans += 2*b+1;
			}else{
				k += a;
				ans += 2*b;
			}
        }
        cout<<"Case #"<<++kase<<": "<<ans<<endl;
    }

    return 0;
}
