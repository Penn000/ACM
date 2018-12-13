/*
time: 2018-08-05
status: AC
link: https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=60&tqId=29474&rp=0&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
	string name;
	int score;
};

vector<Node> vec;

bool cmp1(Node a, Node b){
	return a.score < b.score;
}

bool cmp2(Node a, Node b){
	return a.score > b.score;
}

int main()
{
	int n, op;
	while(cin>>n>>op){
		Node node;
		vec.clear();
		for(int i = 0; i < n; i++){
			cin>>node.name>>node.score;
			vec.push_back(node);
		}
		if(op)stable_sort(vec.begin(), vec.end(), cmp1);
		else stable_sort(vec.begin(), vec.end(), cmp2);

		for(int i = 0; i < n; i++)
		  cout<<vec[i].name<<" "<<vec[i].score<<endl;
	}
	return 0;
}
