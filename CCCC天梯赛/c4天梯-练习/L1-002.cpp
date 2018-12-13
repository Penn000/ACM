//2017-03-15
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int N;
	char ch;
	while(cin>>N>>ch)
	{/*
		if(N < 7){
			cout<<ch<<endl<<N-1<<endl;
			continue;
		}*/
		int n = sqrt(2*(N+1))-1;
		if(n%2==0)n-=1;
//		if(N-(n+1)*(n+1)/2+1 != 0)n-=1;
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < i; j++)
			  cout<<" ";
			for(int j = 0; j < n-2*i; j++)
			  cout<<ch;
			cout<<endl;
		}
		for(int i = 0; i <= n/2; i++){
			for(int j = 0; j < n/2-i; j++)
			  cout<<" ";
			for(int j = 0; j < 2*i+1; j++)
			  cout<<ch;
			cout<<endl;
		}
		cout<<N-(n+1)*(n+1)/2+1<<endl;
	}

    return 0;
}
