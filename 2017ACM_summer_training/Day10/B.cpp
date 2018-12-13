//2017-08-10
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define ll long long

using namespace std;

const int K = 4;
const int N = 500010;
const int M = 12;
const int MOD = 100000;

struct Matrix{  
    ll a[M*M][M*M];  
    int r, c; 
}mat, tmp;  

Matrix multi(Matrix x, Matrix y)//矩阵乘法
{
    Matrix z;
    memset(z.a, 0, sizeof(z.a));  
    z.r = x.r, z.c = y.c;
    for(int i = 0; i < x.r; i++){
        for(int k = 0; k < x.c; k++)//加速优化
        {
            if(x.a[i][k] == 0) continue;
            for(int j = 0; j< y.c; j++)
                z.a[i][j] = (z.a[i][j] + (x.a[i][k] * y.a[k][j]) % MOD) % MOD;
        }
    }
    return z;
}

void Matrix_pow(int n)//矩阵快速幂
{  
    Matrix tmp;
    tmp.c = mat.c;
    tmp.r = mat.r;
    memset(tmp.a, 0, sizeof(tmp.a));
    for(int i = 0; i < tmp.c; i++)
        tmp.a[i][i] = 1;
    while(n){  
        if(n & 1)  
            tmp = multi(tmp, mat);  
        mat = multi(mat, mat);  
        n >>= 1;  
    }  
    int ans = 0;
    for(int i = 0; i < tmp.c; i++)
        ans = (ans + tmp.a[0][i]) % MOD;
    printf("%d\n", ans);
}  

struct AC_automation
{
    //node nodes[N], *root, *superRoot, *cur;
    int nex[M*M][4], fail[M*M], match[M*M];
    int root, CNT;
    int newNode(){
        for(int i = 0; i < K; i++)
            nex[CNT][i] = -1;
        match[CNT++] = 0;
        return CNT-1;
    }
    int Hash(char ch)
    {
        if(ch == 'A')return 0;
        else if(ch == 'C')return 1;
        else if(ch == 'T')return 2;
        else if(ch == 'G')return 3;
    }
    void init(){
        CNT = 0;
        root = newNode();
    }
    void Insert(char s[]){//向字典树中插入一个字符串
        int n = strlen(s);
        int cur = root;
        for(int i = 0; i < n; i++){
            int p = Hash(s[i]);
            if(nex[cur][p] == -1)
                  nex[cur][p] = newNode();
            cur = nex[cur][p];
        }
        match[cur]++;
    }
    void build(){//构建自动机
        queue<int> que;
        fail[root] = root;
        for(int i = 0; i < K; i++){
            if(nex[root][i] == -1)
                nex[root][i] = root;
            else{
                fail[nex[root][i]] = root;
                que.push(nex[root][i]);
            }
        }
        while(!que.empty()){
            int cur = que.front();
            if(match[fail[cur]])match[cur] = 1;
            que.pop();
            for(int i = 0; i < K; i++){
                if(nex[cur][i] == -1){
                    nex[cur][i] = nex[fail[cur]][i];
                }else{
                    fail[nex[cur][i]] = nex[fail[cur]][i];
                    que.push(nex[cur][i]);
                }
            }
        }
    }
    void to_marix(){
        memset(mat.a, 0, sizeof(mat.a));
        mat.r = mat.c = CNT;
		for(int i = 0; i < CNT; i++){
			for(int j = 0; j < 4; j++)
			  	if(!match[nex[i][j]])
                    mat.a[i][nex[i][j]]++;
		}
        // for(int i = 0; i < CNT; i++){
		// 	for(int j = 0; j < CNT; j++)
		// 	  	cout<<mat.a[i][j]<<" ";
        //     cout<<endl;
		// }
    }
};

char str[M];
AC_automation ac;

int main()
{
    int n, m;
    while(scanf("%d%d", &m, &n)!=EOF)
    {
        ac.init();
        for(int i = 0; i < m; i++){
            scanf("%s", str);
            ac.Insert(str);
        }
        ac.build();
        ac.to_marix();
        Matrix_pow(n);
    }

    return 0;
}
