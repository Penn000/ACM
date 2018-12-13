//2017-04-15
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;
const int M = 1005;
const int maxnode = N*M;
int p;

struct DLX
{
	int n, m, sz;//n为矩阵行数，m为矩阵列数，sz为编号
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];//U、D、R、L分别记录上下右左域。Row[i]表示编号为i的节点所在的行号,Col[i]表示编号为i的节点所在的列号
	int H[N], S[M];//H[i]表示指向第i行最前边的节点，S[i]表示第i列1的个数
	int ansd, ans[N];

	void init(int nn, int mm)
	{
		n = nn; m = mm;
		for(int i = 0; i <= m; i++)
		{
			S[i] = 0;//每一行1的个数初始化为0
			U[i] = D[i] = i;//最上面的一行表头C，上下域初始化都为自身
			L[i] = i-1;//左边
			R[i] = i+1;//右边
		}
		R[m] = 0; L[0] = m;//头尾特殊处理
		sz = m;
		for(int i = 1; i <= n; i++)H[i] = -1;
	}
	void link(int r, int c)//第r行第c列为1
	{
		++S[Col[++sz] = c];//编号加1，记录列，所在的列1的个数加1
		Row[sz] = r;//记录行
		/*link上下域：*/
		D[sz] = D[c];
		U[D[c]] = sz;
		U[sz] = c;
		D[c] = sz;
		/*link左右域：*/
		if(H[r] < 0)H[r] = L[sz] = R[sz] = sz;
		else{
			R[sz] = R[H[r]];
			L[R[H[r]]] = sz;
			L[sz] = H[r];
			R[H[r]] = sz;
		}
	}

	void Remove(int c)//删除第c列和其对应的行
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c]; i != c; i = D[i])
		  	for(int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}

	void resume(int c)//恢复第c列和其对应的行
	{
		for(int i = U[c]; i != c; i = U[i])
		  	for(int j = L[i]; j != i; j = L[j])
			  	++S[Col[U[D[j]]=D[U[j]]=j]]; 
		L[R[c]] = R[L[c]] = c;
	}

	void Dance(int d)//d表示选了多少行
	{
		if(ansd != -1 && ansd <= d)return;//剪枝
		if(R[0] == 0)//0号节点为head节点
		{
			if(ansd == -1)ansd = d;
			else if(ansd > d)ansd = d;
			return;
		}
		int c = R[0];
		for(int i = R[0]; i != 0; i = R[i])//选出1最少的列
		  	if(S[i] < S[c])c = i;
		Remove(c);
		for(int i = D[c]; i != c; i = D[i])//枚举第c列存在1节点的行，进行递归处理
		{
			ans[d] = Row[i];//表示第d行选Row[i]
			for(int j = R[i]; j != i; j = R[j])Remove(Col[j]);//将这一行1节点所在的列都删除
			Dance(d+1);
			for(int j = L[i]; j != i; j = L[j])resume(Col[j]);//恢复
		}
		resume(c);
	}
}dlx;

int main()
{
	int n, m, T, x1, x2, y1, y2;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &p);
		dlx.init(p, n*m);
		for(int i = 1; i <= p; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for(int h = x1; h < x2; h++)
				for(int l = y1+1; l <= y2; l++)
					dlx.link(i, h*m+l);
		}
		dlx.ansd = -1;
		dlx.Dance(0);
		printf("%d\n", dlx.ansd);
	}

    return 0;
}
