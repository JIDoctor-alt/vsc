#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G,rG;//正图、反图
vector<int> postOrder;//逆拓扑序列
vector<int> sccNo;//存储每个节点属于哪个强连通片
vector<bool> visited;
int sccflag;//强连通片的编号
int N,M;
//用于得到逆拓扑序列
void dfs1(int x)
{
    visited[x] = true;
    for(auto &w : G[x])
        if(!visited[w])
            dfs1(w);
    postOrder.push_back(x);
}
//对强连通片进行分类
void dfs2(int x)
{
    sccNo[x] = sccflag;
    for(auto &w : rG[x])
        if(sccNo[w] == 0)
            dfs2(w);
}
//kosaraju算法
void kosaraju()
{   //找出逆拓扑序列
    for(int i = 0;i < N;++i)
    {
        if(!visited[i])
            dfs1(i);
    }//翻转逆拓扑序列
    reverse(postOrder.begin(),postOrder.end());
    fill(sccNo.begin(),sccNo.end(),0);
    for(auto x : postOrder)//开始对强连通片进行分类
    {
        if(sccNo[x] == 0)
        {
            ++sccflag;//编号
            dfs2(x);
        }
    }
}
int main()
{
    cin>>N>>M;
    G.resize(N);
    rG.resize(N);
    sccNo.resize(N);
    visited = vector<bool>(N,false);
    while (M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    kosaraju();
    for(int i = 0;i < N;++i)
        cout<<"V"<<i<<" "<<char('A' + i)<<" : "<<sccNo[i]<<endl;
    return 0;
}
/*  Test 7个节点(编号从0开始) 13条边的问题
7 13
0 1
0 2
0 5
1 2
1 3
3 0
3 2
4 2
4 6
5 0
5 2
6 3
6 4


*/