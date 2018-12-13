//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int M[20] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};
int main()
{
	int n;
	string id;
	while(cin>>n)
	{
		bool fg = true, ok = true;
		while(n--)
		{
			cin>>id;
			int tmp = 0;
			fg = true;
			for(int i = 0; i < 17; i++)
			{
				if(id[i]>='0' && id[i]<='9')
				{
					tmp += (id[i]-'0')*w[i];
				}else{
					fg = false;
					ok = false;
					cout<<id<<endl;
					break;
				}
			}
			if(fg){
				int z = tmp%11;
				if(z == 2 && id[17] == 'X')continue;
				if(M[z] != id[17]-'0'){
					cout<<id<<endl;
					ok = false;
				}
			}
		}
		if(ok)cout<<"All passed"<<endl;
	}

	return 0;
}
