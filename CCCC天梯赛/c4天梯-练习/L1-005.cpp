//2017-03-15
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;
struct node
{
	string id;
	int b;
}stu[N];

int main()
{
	string id;
	int n, m, a, b;
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>id>>a>>b;
			stu[a].id = id;
			stu[a].b = b;
		}
		cin>>m;
		int q;
		while(m--){
			cin>>q;
			cout<<stu[q].id<<" "<<stu[q].b<<endl;
		}
	}

    return 0;
}
