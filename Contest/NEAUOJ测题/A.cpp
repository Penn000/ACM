#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000000;

int arr[N];

int main()
{
	int n, k;
	while(cin>>n>>k){
		if((!(n&1) && (k&1)) || 9*n < k){
			cout<<-1<<endl;
			continue;
		}
		for(int i = 0; i < n/2; i++){
			if(k >= 18){
				arr[i] = 9;
				k -= 18;
			}else if(k > 0){
				arr[i] = k/2;
				k -= 2*arr[i];
			}else{
				arr[i] = 0;
			}
		}
		for(int i = 0; i < n/2; i++)
		  printf("%d", arr[i]);
		if(n&1)printf("%d", k);
		for(int i = n/2-1; i >= 0; i--)
		  printf("%d", arr[i]);
		printf("\n");
	}

	return 0;
}
