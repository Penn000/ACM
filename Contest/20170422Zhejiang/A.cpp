#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T, n, Ko, To;
	cin>>T;
	while(T--)
	{
		cin>>n;
		Ko = To = 0;
		int feedback;
		for(int i = 0; i < n; i++)
		{
			cin>>feedback;
			if(feedback == 1){
				Ko += 1;
			}else if(feedback == 2){
				To += 1;
			}else if(feedback == 3){
				Ko += 1;
				To += 1;
			}else{
				Ko -= 1;
				To -= 1;
			}
		}
		if(Ko > To)cout<<"Kobayashi"<<endl;
		else if(Ko < To)cout<<"Tohru"<<endl;
		else cout<<"Draw"<<endl;
	}
	return 0;
}
