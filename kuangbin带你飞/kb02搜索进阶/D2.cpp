#include<bits/stdc++.h>
#define cl(a,b) memset(a,b,sizeof(a));
#define LL long long
#define out(x) cout<<x<<endl;
using namespace std;
const int maxn=105;
const int inf=9999999;

int n,m,k,d;
int dir[][2]={{0,1},{1,0},{-1,0},{0,-1},{0,0}};///对应的四个方向是ESNW，(0,0)表示在原地
struct castle{//炮台
    char dir;
    int t,v;
    void clear(){
        dir='*';t=v=0;
    }
    castle(){}
    castle(char dir,int t,int v){
        this->dir=dir;this->t=t;this->v=v;
    }
}castles[maxn][maxn];
bool vis[1005][maxn][maxn];//用int会超内存,int是4字节，bool是一个字节
struct node{//搜索的状态节点
    int x,y,step;
    node(){};
    node(int x,int y,int step){
        this->x=x;this->y=y;this->step=step;
    }
    bool operator<(const node& tt) const{
        return step>tt.step;
    }
};
bool pan(node s){
    if(s.x>=0&&s.x<=n&&s.y>=0&&s.y<=m)return true;
    return false;
}
bool isEnable(node s){///四个方向找最近的城堡，找出这个时刻这个位置是否有子弹。

    //printf("%d %d\n",s.x,s.y);
    if(castles[s.x][s.y].dir!='*')return false;
    ///-->E，表示往右看有没有炮台，有的话取第一个
    node tmp=s;
    castle cs;
    int time=s.step;
    while(pan(tmp)&&castles[tmp.x][tmp.y].dir=='*'){
        tmp.x+=dir[0][0];
        tmp.y+=dir[0][1];
    }
    if(pan(tmp))cs=castles[tmp.x][tmp.y];
    if(pan(tmp)&&cs.dir=='W'){
        int dis=tmp.y-s.y;
        if(dis%cs.v==0){
            if((time-dis/cs.v)>=0&&(time-dis/cs.v)%cs.t==0)
                return false;
        }
    }
    ///-->S
    tmp=s;
    while(pan(tmp)&&castles[tmp.x][tmp.y].dir=='*'){
        tmp.x+=dir[1][0];
        tmp.y+=dir[1][1];
    }
    if(pan(tmp))cs=castles[tmp.x][tmp.y];
    if(pan(tmp)&&cs.dir=='N'){
        int dis=tmp.x-s.x;
        if(dis%cs.v==0){
            if((time-dis/cs.v)>=0&&(time-dis/cs.v)%cs.t==0){
                return false;
            }
        }
    }
    ///-->N
    tmp=s;
    while(pan(tmp)&&castles[tmp.x][tmp.y].dir=='*'){
        tmp.x+=dir[2][0];
        tmp.y+=dir[2][1];
    }
    if(pan(tmp))cs=castles[tmp.x][tmp.y];
    if(pan(tmp)&&cs.dir=='S'){
        int dis=s.x-tmp.x;
        if(dis%cs.v==0){
            if((time-dis/cs.v)>=0&&(time-dis/cs.v)%cs.t==0){
                return false;
            }
        }
    }
    ///-->W
    tmp=s;
    while(pan(tmp)&&castles[tmp.x][tmp.y].dir=='*'){
        tmp.x+=dir[3][0];
        tmp.y+=dir[3][1];
    }
    if(pan(tmp))cs=castles[tmp.x][tmp.y];
    if(pan(tmp)&&cs.dir=='E'){
        int dis=s.y-tmp.y;
        if(dis%cs.v==0){
            if((time-dis/cs.v)>=0&&(time-dis/cs.v)%cs.t==0){
                return false;
            }
        }
    }
    return true;
}

int bfs(){
    cl(vis,false);
    priority_queue<node> q;
    q.push(node(0,0,0));
    vis[0][0][0]=true;
    while(!q.empty()){
        node s=q.top();q.pop();
        for(int i=0;i<5;i++){
            node tmp=s;
            tmp.x+=dir[i][0];
            tmp.y+=dir[i][1];
            tmp.step++;
            if(tmp.x==n&&tmp.y==m){
                if(castles[n][m].dir=='*')return tmp.step;
                else return -1;
            }
            if(tmp.step>d)return -1;
            if(pan(tmp)&&!vis[tmp.step][tmp.x][tmp.y]){
                if(isEnable(tmp)){
                    vis[tmp.step][tmp.x][tmp.y]=true;
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d%d%d%d",&n,&m,&k,&d)){

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                castles[i][j].clear();
            }
        }

        for(int i=0;i<k;i++){
            char c[2];
            int t,v,x,y;
            scanf("%s%d%d%d%d",c,&t,&v,&x,&y);
            castles[x][y]=castle(c[0],t,v);
        }
        int ans=bfs();
        if(ans==-1){
            puts("Bad luck!");
        }
        else {
            printf("%d\n",ans);
        }
    }
    return 0;
}