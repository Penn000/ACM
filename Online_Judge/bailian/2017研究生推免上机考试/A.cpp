//2018-02-03
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int book[110];

int main()
{
	int n;
	while(cin>>n){
		memset(book, 0, sizeof(book));
		while(n > 1){
			for(int i = 2; i <= n; i++){
				if(n%i == 0){
					book[i]++;
					n /= i;
				}
			}
		}
		bool first = 1;
		for(int i = 2; i < 100; i++){
			if(book[i]){
				if(first){
					first = 0;
				}else
				  	cout<<"*";
				if(book[i] > 1){
					cout<<i<<"^"<<book[i];
				}else
				  	cout<<i;
			}
		}
		cout<<endl;
	}

	return 0;
}
