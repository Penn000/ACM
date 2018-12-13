#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

int mat1[N][N], mat2[N][N], mat3[N][N];

int main()
{
	int Ra, Ca, Rb, Cb;
	cin>>Ra>>Ca;
	for(int i = 0; i < Ra; i++)
	  for(int j = 0; j < Ca; j++)
		cin>>mat1[i][j];
	cin>>Rb>>Cb;
	for(int i = 0; i < Rb; i++)
	  for(int j = 0; j < Cb; j++)
		cin>>mat2[i][j];
	if(Ca != Rb){
		cout<<"Error: "<<Ca<<" != "<<Rb<<endl;
	}else{
		for(int i = 0; i < Ra; i++){
			for(int j = 0; j < Cb; j++){
				mat3[i][j] = 0;
				for(int k = 0; k < Ca; k++)
				  mat3[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
		cout<<Ra<<" "<<Cb<<endl;
		for(int i = 0; i < Ra; i++){
			for(int j = 0; j < Cb; j++){
				if(j == Cb-1)
					cout<<mat3[i][j]<<endl;
				else
					cout<<mat3[i][j]<<" ";
			}
		}	
	}

	return 0;
}
