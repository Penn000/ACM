#include <iostream>
#include <cstdio>
#include <stdlib.h>
#define N 100000

using namespace std;

void MaxSum(int a[], int n);

int a[N];

int main(void)
{
	int n, i;

    while(cin>>n&&n)
	{
       for (i = 0; i < n; i++)
       scanf("%d", &a[i]);

       MaxSum(a, n);
	}

	 return 0;
}

void MaxSum(int a[], int n)
{
	int i = 0, max_sum, temp, bg, Bg, ed, Ed;

    max_sum = temp = a[0];
    bg = Bg = ed = Ed = 0;
    for(i = 1; i < n; i++)
	{
    	if(temp < 0)
		{
		   temp = 0;
		   bg = i;    
		}
		temp += a[i];
		ed = i;
		if(temp > max_sum)
		{
			max_sum = temp;
			Bg = bg;
			Ed = ed;
		}
														     
	}
	if(max_sum>=0)
		printf("%d %d %d\n", max_sum, a[Bg], a[Ed]);
	else printf("0 %d %d\n", a[0], a[n-1]);

}
