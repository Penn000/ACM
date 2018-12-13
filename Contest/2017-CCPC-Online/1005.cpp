//2017-08-19
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[20] = {0, 4, 4, 6, 6, 7, 8, 8, 8};

int main()
{
    int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		/*if(n <= 8){
			printf("%d\n", arr[n]);
			continue;
		}*/
		int len = sqrt(n/2);
		int area = 2*len*len;
		if(n-area == 0){
			printf("%d\n", len*4);
		}else if(n <= area+len-1){
			printf("%d\n", len*4+1);
		}
		else if(n-area <= 2*len){
			printf("%d\n", len*4+2);
		}else if(n <= 2*(len+1)*(len+1)-(len+1+1)){
			printf("%d\n", len*4+3);
		}
		else{
			printf("%d\n", (len+1)*4);
		}
	}

	return 0;
}
