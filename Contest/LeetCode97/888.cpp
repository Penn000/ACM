#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> uncommonFromSentences(string A, string B) {
	map<string, int> mpA, mpB;
	vector<string> ans;
	map<string, int>::iterator iter;
	string str;
	stringstream sA(A);
	while(sA>>str){
		mpA[str]++;
	}
	stringstream sB(B);
	while(sB>>str){
		mpB[str]++;
	}
	for(iter = mpA.begin(); iter != mpA.end(); iter++){
		if(iter->second == 1 && mpB[iter->first]==0)
		  ans.push_back(iter->first);
	}
	for(iter = mpB.begin(); iter != mpB.end(); iter++){
		if(iter->second == 1 && mpA[iter->first]==0)
		  ans.push_back(iter->first);
	}
	return ans;
}
int main()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);
	vector<string> vec = uncommonFromSentences(A, B);
	for(string str: vec){
		cout<<str<<endl;
	}

	return 0;
}
