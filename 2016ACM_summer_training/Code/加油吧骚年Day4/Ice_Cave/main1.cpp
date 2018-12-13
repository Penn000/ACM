#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
#include <cmath>  
#include <cstdlib>  
#include <limits>  
#include <queue>  
  
using namespace std;  
typedef  long long LL;  
  
#define N 10100  
#define met(a, b) memset (a, b, sizeof (a))  
  
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
  
struct node  
{  
    int x, y;  
}SA, EN;  
  
int n, m;  
char str[N][N];  
  
void BFS (node SA)  
{  
    queue <node> que;  
    que.push (SA);  
  
    while (que.size ())  
    {  
	        SA = que.front (); que.pop ();  
	  
	        for (int i=0; i<4; i++)  
	        {  
			            node p = SA;  
			            p.x += dir[i][0];  
			            p.y += dir[i][1];  
			  
			            if (p.x>0 && p.x<=n && p.y>0 && p.y<=m)  
			            {  
		                if (str[p.x][p.y] == 'X' && p.x == EN.x && p.y == EN.y) 
		                {  
		                    puts ("YES");  
		                    return;  
		                }  
				  
	                else if (str[p.x][p.y] == '.')  
		                {  
		                    str[p.x][p.y] = 'X';  
		                    que.push (p);  
		                }  
			            }  
			        }  
	    }  
    puts ("NO");  
}  
  
int main ()  
{  
    int sax, say, enx, eny;  
  
    while (scanf ("%d %d", &n, &m) != EOF)  
    {  
	        for (int i=1; i<=n; i++)  
	        {  
			            getchar ();  
			            for (int j=1; j<=m; j++)  
			            scanf ("%c", &str[i][j]);  
			        }  
	  
	        scanf ("%d %d %d %d", &sax, &say, &enx, &eny);  
	  
	        SA = (node) {sax, say}, EN = (node) {enx, eny};  
	  
	        BFS (SA);  
	    }  
    return 0;  
}  



