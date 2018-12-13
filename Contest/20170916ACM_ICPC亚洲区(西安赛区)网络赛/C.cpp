#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100000;

char x[N];
int arr[N];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", x);
		int ans = 0;
		int n = strlen(x);
		for(int i = 0; i < n; i++){
			arr[i] = (x[i]-'0');
			ans += arr[i];
		}
		int num = 0;
		for(num = 1; num <= 233; num++){
			if(((ans%233)*(num%233)) % 233 == 0){
				break;
			}
		}
		while(num){
			if(num < 9){
				printf("%d\n", num);
				break;
			}
			printf("9");
			num -= 9;
		}
	}

	return 0;
}
