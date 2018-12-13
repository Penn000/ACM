//2017-03-09
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;
const int M = 1010;
const int maxnode = N*M;
/*例如如下01矩阵
1 1 0 0
0 0 0 1
0 1 1 1
1 0 1 0
其4个数组为：
      0  1  2  3  4  5  6  7  8  9  10 11 12
up    0  11 8  12 10 1  2  4  6  3  7  5  9
down  0  5  6  9  7  11 8  10 2  12 4  1  3
left  4  0  1  2  3  6  5  7  10 8  9  12 11
right 1  2  3  4  0  6  5  7  9  10 8  12 11
因为上面的01矩阵有4个列，8个1，我们把头节点head编号为0。列分别编号为1,2,3,4。第一行的两个1编号为5,6，第二行的一个1编号为7，第三行三个1编号为8,9,10。第四行两个1，编号为11,12。编号的顺序都是从左到右。这样一来，1列的下一个节点就是编号为5的1，编号为5的1的下面又是编号11的1，编号为5的1的左边和右边都是编号为6的1  
即为：
	0 1 2 3 4
	  5 6   
	        7
	    8 9 10
	  11  12  
*/
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

	bool Dance(int d)//d表示选了多少行
	{
		if(R[0] == 0)//0号节点为head节点
		{
			printf("%d ", d);
			for(int i = 0; i < d; i++)
			  	if(i == d-1)printf("%d\n", ans[i]);
				else printf("%d ", ans[i]);
			return true;
		}
		int c = R[0];
		for(int i = R[0]; i != 0; i = R[i])//选出1最少的列
		  	if(S[i] < S[c])c = i;
		Remove(c);
		for(int i = D[c]; i != c; i = D[i])//枚举第c列存在1节点的行，进行递归处理
		{
			ans[d] = Row[i];//表示第d行选Row[i]
			for(int j = R[i]; j != i; j = R[j])Remove(Col[j]);//将这一行1节点所在的列都删除
			if(Dance(d+1))return true;
			for(int j = L[i]; j != i; j = L[j])resume(Col[j]);//恢复
		}
		resume(c);
		return false;
	}
}dlx;

int main()
{
	int n, m, c, tmp;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		dlx.init(n, m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &c);
			for(int j = 0; j < c; j++)
			{
				scanf("%d", &tmp);
				dlx.link(i, tmp);
			}
		}
		if(!dlx.Dance(0))printf("NO\n");
	}

    return 0;
}
