#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int father[110];
int connect[110][110];
int find(int x){
    return x == father[x] ? x : find(father[x]);
}
void unite(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx < ny)
        father[ny] = nx;
    else if(nx > ny)
        father[nx] = ny;
}
int main()
{
    for(int i = 0;i < 110;++i)
        father[i] = i;
    memset(connect,0,sizeof(connect));
    int N,M,K;
    cin>>N>>M>>K;
    for(int i = 0;i < M;i++)
    {
        int x,y,fl;
        cin>>x>>y>>fl;
        //如果是朋友就并起来
        if(fl == 1)
            unite(x,y);
        
        connect[x][y] = connect[y][x] = fl;
        
    }
    //注意输入数据的正确性，顺序的正确性
    //cin>>K;
    for(int i = 0;i < K;i++)
    {
        int na,nb;
        cin>>na>>nb;

        if((find(na) == find(nb))&&connect[na][nb] != -1)
            cout<<"No problem"<<endl;
        else if((find(na) != find(nb))&&connect[na][nb] != -1)
            cout<<"OK"<<endl;
        else if((find(na)== find(nb))&&connect[na][nb] == -1)
            cout<<"OK but..."<<endl;
        else if((find(na) != find(nb))&&connect[na][nb] == -1)
            cout<<"No way"<<endl;
    }

}