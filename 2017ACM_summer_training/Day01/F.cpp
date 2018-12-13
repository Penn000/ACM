//2017-08-01
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;
char arr[N];
int n, a, b, k;
int shot[N];

int main(){
    while(scanf("%d%d%d%d", &n, &a, &b, &k)!=EOF){
        scanf("%s", arr);
        int num = 0, tmp = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == '0')tmp++;
            else tmp = 0;
            if(tmp == b){
                tmp = 0;
                shot[num++] = i+1;
            }
        }
        printf("%d\n", num-a+1);
        for(int i = 0; i < num-a+1; i++)
            printf("%d ", shot[i]);
        printf("\n");
    }

    return 0;
}