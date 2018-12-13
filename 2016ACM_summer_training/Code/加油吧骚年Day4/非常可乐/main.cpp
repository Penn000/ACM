#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int date;
	int step;
}q[10005];

int turn(int a, int b, int c)
{
	return a*10000+b*100+c;
}

int main()
{
	int bottle[3], head, tail, a[3];
	while(cin>>bottle[0]>>bottle[1]>>bottle[2]&&bottle[0]&&bottle[1]&&bottle[2])
	{
		if(bottle[0]%2)cout<<"NO"<<endl;
		else
		{
			if(bottle[1]<bottle[2])swap(bottle[1], bottle[2]);
			a[0] = bottle[0]; a[1] = 0; a[2] = 0;
			int res = turn(bottle[0]/2, bottle[0]/2, 0);
			head = 0; tail = 1;
			q[head].date = turn(a[0], a[1], a[2]);
			int cnt = 0;
			while(head<tail)
			{
				int tmp = q[head].date;
				for(int i = 0; i < 3; i++)
				{
					a[0] = tmp/10000; 
					a[1] = (tmp%10000)/100; 
					a[2] = tmp%100;
					if(a[i])
					{
						for(int j = 0; j <3; j++)
						{
							a[0] = tmp/10000; 
							a[1] = (tmp%10000)/100; 
							a[2] = tmp%100;
							if(j!=i&&a[j]<bottle[j])
							{
								int add = bottle[j]-a[j];
								a[j] = bottle[j];
								a[i] -= add;
								if(res == turn(a[0], a[1], a[2]))
								{
									cout << "YES" << endl;
									break;																									
								}else
								{
									q[tail].date = turn(a[0], a[1], a[2]);
									tail++;
								}
							}
						}
					}
				}
				head++;
			}
		}
	}

	return 0;
}
