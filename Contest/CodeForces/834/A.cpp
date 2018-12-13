//2017-08-18
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const char cw[4] = {'^', '>', 'v', '<'};
const char ccw[4] = {'^', '<', 'v', '>'};

int main()
{
	int n;
    char ch1, ch2;
	while(cin>>ch1>>ch2){
		cin>>n;
		n = n%4;
		bool fg1 = false, fg2 = false;
		for(int i = 0; i < 4; i++){
			if(cw[i] == ch1 && cw[(i+n)%4] == ch2){
				fg1 = true;
			}
		}
		for(int i = 0; i < 4; i++){
			if(ccw[i] == ch1 && ccw[(i+n)%4] == ch2){
				fg2 = true;
			}
		}
		if(fg1 && !fg2)
			cout<<"cw"<<endl;
		else if(!fg1 && fg2)
			cout<<"ccw"<<endl;
		else 
			cout<<"undefined"<<endl;
	}

	return 0;
}
