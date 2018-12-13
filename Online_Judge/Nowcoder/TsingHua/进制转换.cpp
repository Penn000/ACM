/*
time: 2018-08-05
status: AC
link: https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=60&tqId=29473&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string divise(string a, int b, int& reminder){
	string ans = "";
	int len = a.length();
	int r = 0, dig;
	for(int i = 0; i < len; i++){
		int num = 10*r+a[i]-'0';
		dig = num/b;
		r = num%b;
		ans.append(1, dig+'0');
	}
	reminder = r;
	return ans;
}

bool equZero(string str){
	for(int i = 0; i < (int)str.length(); i++)
	  if(str[i] != '0')return false;
	return true;
}

int main()
{
	string n;
	while(cin>>n){
		stack<int> sk;
		int reminder;
		while(!equZero(n)){
			n = divise(n, 2, reminder);
			sk.push(reminder);
		}
		while(!sk.empty()){
			cout<<sk.top();
			sk.pop();
		}
		cout<<endl;
	}
	return 0;
}
