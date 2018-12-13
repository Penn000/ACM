//2017-02-23
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
	int x, y, pre;
}q[1000];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void print(int pos)
{
	if(pos == -1)return;
	print(q[pos].pre);
	cout<<"("<<q[pos].x<<", "<<q[pos].y<<")"<<endl;
}

int main()
{
	int maze[5][5];
	while(cin>>maze[0][0]>>maze[0][1]>>maze[0][2]>>maze[0][3]>>maze[0][4]){
		for(int i = 1; i < 5; i++)
		  for(int j = 0; j < 5; j++)
			cin>>maze[i][j];
		q[0].x = 0;
		q[0].y = 0;
		q[0].pre = -1;
		maze[0][0] = 1;
		int head = 0, tail = 1;
		while(head < tail)
		{
			int x = q[head].x;
			int y = q[head].y;
			if(x==4 && y==4){
				print(head);
				break;
			}
			for(int i = 0; i < 4; i++)
			{
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<5&&ny>=0&&ny<5&&!maze[nx][ny]){
					q[tail].x = nx;
					q[tail].y = ny;
					q[tail].pre = head;
					tail++;
				}
			}
			head++;
		}
	}

	return 0;
}
