//2017-07-19
#include <iostream>

using namespace std;

const int N = 30010;
int n, m, fa[N];

void init(){
    for(int i = 0; i < N; i++)
        fa[i] = i;
}

int getfa(int x){
    if(x == fa[x])return x;
    else return fa[x] = getfa(fa[x]);
}

void merge0(int a, int b){
    int af = getfa(a);
    int bf = getfa(b);
    if(af != bf)
        fa[bf] = af;
}

int main(){
    while(cin>>n>>m){
        if(!n && !m)break;
        init();
        int k, a, b;
        while(m--){
            cin>>k>>a;
            for(int i = 0; i < k-1; i++){
                cin>>b;
                merge0(a, b);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(getfa(i) == fa[0])
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
