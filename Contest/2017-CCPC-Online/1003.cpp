//2017-08-19
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3050;
bool G[N][N];
int n;

void work(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(G[i][j] == 1){
				for(int k = j+1; k <= n; k++){
					if(G[i][k] == 1 && G[j][k] == 1){
						printf("Bad Team!\n");return;
					}
				}
			}
			if(G[i][j] == 0){
				for(int k = j+1; k <= n; k++){
					if(G[i][k] == 0 && G[j][k] == 0){
						printf("Bad Team!\n");return;
					}
				}
			}
		}
	}
	printf("Great Team!\n");
}

int main()
{
    int T, a;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n-1; i++){
			for(int j = i+1; j <= n; j++){
				scanf("%d", &a);
				G[j][i] = G[i][j] = a;
			}
		}
		/*for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
			  cout<<G[i][j]<<" ";
			cout<<endl;
		}*/
		work();
	}

	return 0;
}
