//2018-03-15
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

struct Node{
	string name;
	int len, uniLen;

	bool operator<(Node node){
		if(uniLen == node.uniLen)
		  	return len < node.len;
		return uniLen > node.uniLen;
	}
}person[N];

int arr[1010];

int main()
{
	int n;
	while(cin >> n){
		string str;
		for(int i = 0; i < n; i++){
			cin>>person[i].name>>person[i].len;
			for(int j = 0; j < person[i].len; j++)
			  	scanf("%d", &arr[j]);
			sort(arr, arr+person[i].len);
			int cnt = unique(arr, arr+person[i].len) - arr;
			person[i].uniLen = cnt;
		}
		sort(person, person+n);
		if(n == 0)cout<<"- - -"<<endl;
		else if(n == 1)cout<<person[0].name<<" - -"<<endl;
		else if(n == 2)cout<<person[0].name<<" "<<person[1].name<<" -"<<endl;
		else cout<<person[0].name<<" "<<person[1].name<<" "<<person[2].name<<endl;
	}

	return 0;
}
