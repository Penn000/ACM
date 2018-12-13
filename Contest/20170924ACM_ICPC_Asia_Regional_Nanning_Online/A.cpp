#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
double a[6][6];
int O1[N], O2[N];

int main()
{
	for(int i = 1; i < 5; i++)
	  	for(int j = 1; j < 5; j++)
		  	cin>>a[i][j];
	int k = 0, l = 0;
	while(1){
		scanf("%d", &O1[k++]);
		if(getchar() == '\n')break;
	}
	while(1){
		scanf("%d", &O2[l++]);
		if(getchar() == '\n')break;
	}
	int I, J;
	cin>>I>>J;
	double p1 = 1, p2 = 1;
	for(int i = 1; i < k; i++)
	  	p1 *= a[O1[i-1]][O1[i]];
	for(int i = 1; i < l; i++)
	  	p2 *= a[O2[i-1]][O2[i]];
	printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n", p1, p2, 1.0/(1.0-a[I][I]), 1.0/(1.0-a[J][J]));

	return 0;
}
