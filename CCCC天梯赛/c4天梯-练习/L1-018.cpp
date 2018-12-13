//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int h, m;
	while(scanf("%d:%d", &h, &m)!=EOF)
	{
		if(h>12 || (h==12&&m>0))
		{
			h-=12;
			if(m>0)h++;
			while(h--)
			{
				printf("Dang");
			}
			printf("\n");
		}else{
			int a[5], b[5];
			a[0] = h/10;
			a[1] = h%10;
			b[0] = m/10;
			b[1] = m%10;
			printf("Only %d%d:%d%d.  Too early to Dang.\n", a[0], a[1], b[0], b[1]);
		}
	}

    return 0;
}
