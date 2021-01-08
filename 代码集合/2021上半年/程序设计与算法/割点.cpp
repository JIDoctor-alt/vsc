#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector< vector<int> > G;//无向图
vector<int> d,low;//最早开始时间,该节点所能访问的最早开始时间
vector<bool> isArticulation;//记录某个节点是否为割点，初值为false
vector<pii> bridges;//在无向图， 没有重边的情况下求割边
int N,M;//节点，边
int ts;//时间戳
void dfs(int x,int pa)
{
    //low的初始值设置为d[x]
    low[x] = d[x] = ++ts;
    int child = 0;//记录x的孩子节点
    for(auto &w : G[x])
    {
        if(d[w] == 0)
        {
            ++child;
            dfs(w,x);//w的父节点为x
            low[x] = min(low[x],low[w]);//x的low值为该x节点和邻节点中low值的最小
            if(pa != -1 && low[w] >= d[x])//x邻接点不是x的根节点，邻节点w的low值大于x节点的最早开始时间(low[w]要比d[x]晚)
                isArticulation[x] = true; //（说明删掉x节点，邻接点w就访问不到x的祖先了，即割点）

            //求割边
            if(low[w] > d[x])
                bridges.push_back({min(x,w),max(x,w)});
        }else if(w != pa && d[w] < d[x])//邻接点已经访问过且不是父节点（d[w] ==0 好像已经更新了），比x节点早
            low[x] = min(low[x],d[w]);//更新x的low值
    }
    if(pa == -1 && child > 1)//是根节点
        isArticulation[x] = true;
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    d.resize(N+1);
    low.resize(N+1);
    isArticulation.resize(N+1);
    while (M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1;i <= N;++i)
    {
        if(d[i] == 0)
            dfs(i,-1);//注意一定要有根节点（根节点的父亲设置为-1）
    }
    int cnt = count_if(isArticulation.begin(),isArticulation.end(),[](auto x){return x;});
    cout<<"Cut Point Number : "<<cnt<<endl;
    for(int i = 0;i <= N;++i)
        if(isArticulation[i])
            cout<<i<<" ";
    cout<<endl;
    cout<<"========Cut Edge========="<<endl;
    for(auto &w : bridges)
        cout<<w.first<<"->"<<w.second<<endl;
    return 0;
}
//N个节点（从1开始编号 到 N） M条边
/*
6 7
1 2
1 3
4 1
2 5
3 5
4 5
5 6
*/