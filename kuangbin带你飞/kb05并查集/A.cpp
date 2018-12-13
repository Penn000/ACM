//2017-07-17
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;
int n, d;
int fa[N], x[N], y[N];
bool isRepaired[N];

void init(){
    for(int i = 0; i < N; i++){
        fa[i] = i;
        isRepaired[i] = false;
    }
}

int getfa(int x){
    if(fa[x] == x)return x;
    return fa[x] = getfa(fa[x]);
}

void merge0(int a, int b){
    int af = getfa(a);
    int bf = getfa(b);
    if(af != bf){
        fa[bf] = af;
    }
}

int main(){
    char op[3];
    int a, b;
    while(scanf("%d%d", &n, &d) != EOF){
		init();
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &x[i], &y[i]);
        }
		getchar();
        while(scanf("%s", op)!=EOF){
            if(op[0] == 'O'){
                scanf("%d", &a);
                isRepaired[a] = true;
                for(int i = 1; i <= n; i++){
                    if(isRepaired[i] && (x[i]-x[a])*(x[i]-x[a])+(y[i]-y[a])*(y[i]-y[a])<=d*d){
                        merge0(i, a);
                    }
                }
            }else{
                scanf("%d%d", &a, &b);
                int af = getfa(a);
                int bf = getfa(b);
                if(af == bf) printf("SUCCESS\n");
                else printf("FAIL\n");
            }
        }
    }

    return 0;
}
