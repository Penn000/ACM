//2016.10.1
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int format, hh, mm;
	while(scanf("%d", &format)!=EOF)
	{
		scanf("%d:%d", &hh, &mm);
		if(format==12)
		{
			if(hh == 0)hh++;
			else if(hh<1 || hh > 12)
			{
				if(hh%10 == 0)hh = 10;
				else hh %= 10;
			}
			if(mm<0 || mm > 59)mm%=10;
			printf("%02d:%02d\n", hh, mm);	
		}else
		{
			if(hh<0 || hh > 23)hh%=10;
			if(mm<0 || mm > 59)mm%=10;
			printf("%02d:%02d\n", hh, mm);
		}
	}

    return 0;
}
