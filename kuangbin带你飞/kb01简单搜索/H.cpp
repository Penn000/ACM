//2017-02-24
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int a, b, step, pre, op;
}q[1000];

int pots[3], POT[3], book[105][105];
string option[10] = {"", "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};

void fill(int i)
{
	pots[i] = POT[i];
}

void drop(int i)
{
	pots[i] = 0;
}

void pour(int i, int j)
{
	if(pots[i] > POT[j]-pots[j]){
		pots[i] -= (POT[j]-pots[j]);
		pots[j] = POT[j];
	}else{
		pots[j] += pots[i];
		pots[i] = 0;
	}
}

void init(int a, int b)
{
	pots[1] = a;
	pots[2] = b;
}

void push(int pos, int a, int b, int step, int pre, int op)
{
	q[pos].a = a;
	q[pos].b = b;
	q[pos].step = step;
	q[pos].pre = pre;
	q[pos].op = op;
}

void print(int pos)
{
	if(q[pos].pre == -1)return;
	print(q[pos].pre);
	cout<<option[q[pos].op]<<endl;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int C, a, b, step;
	while(cin>>POT[1]>>POT[2]>>C)
	{
		int head = 0, tail = 1;
		q[0].a = 0;
		q[0].b = 0;
		q[0].step = 0;
		q[0].pre = -1;
		memset(book, 0, sizeof(book));
		book[0][0] = 1;
		while(head < tail)
		{
			a = q[head].a;
			b = q[head].b;
			step = q[head].step;

			if(a==C || b==C){
				cout<<step<<endl;
				print(head);
				break;
			}

			init(a, b);
			fill(1);
			if(!book[pots[1]][pots[2]]){
				book[pots[1]][pots[2]] = 1;
				push(tail, pots[1], pots[2], step+1, head, 1);
				tail++;
			}

			init(a, b);
			fill(2);
			if(!book[pots[1]][pots[2]]){
				book[pots[1]][pots[2]] = 1;
				push(tail, pots[1], pots[2], step+1, head, 2);
				tail++;
			}

			if(a>0){
				init(a, b);
				drop(1);
				if(!book[pots[1]][pots[2]]){
					book[pots[1]][pots[2]] = 1;
					push(tail, pots[1], pots[2], step+1, head, 3);
					tail++;
				}
			}

			if(b>0){
				init(a, b);
				drop(2);
				if(!book[pots[1]][pots[2]]){
					book[pots[1]][pots[2]] = 1;
					push(tail, pots[1], pots[2], step+1, head, 4);
					tail++;
				}
			}

			init(a, b);
			pour(1, 2);
			if(!book[pots[1]][pots[2]]){
				book[pots[1]][pots[2]] = 1;
				push(tail, pots[1], pots[2], step+1, head, 5);
				tail++;
			}

			init(a, b);
			pour(2, 1);
			if(!book[pots[1]][pots[2]]){
				book[pots[1]][pots[2]] = 1;
				push(tail, pots[1], pots[2], step+1, head, 6);
				tail++;
			}

			head++;
		}
		if(head>=tail)cout<<"impossible"<<endl;
	}
	return 0;
}
