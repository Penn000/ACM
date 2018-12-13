#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200;
char num[N];
int dp[N][10][2][3];

int main()
{
    int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", num);
		int n = strlen(num);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < 2; k++){
					for(int p = 0; p < 3; p++){
						if(dp[i][j][k][p] != 0){
							int l, r;
							l = j; r = (k==1 ? num[i]-'0' : 9);
							for(int x = l; x <= r; x++){
								if(p == 0){
									dp[i+1][x][][] += dp[i][j][k][p];
								}else if(p == 1){

								}else{

								}
							}
						}
					}
				}
			}
	}

	return 0;
}
