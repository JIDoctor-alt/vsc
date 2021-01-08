#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G,rG;//正图、反图
vector<int> postOrder;//逆拓扑序列
vector<int> sccNo;//存储每个节点属于哪个强连通片
vector<bool> visited;
vector<vector<int> > res;
int sccflag;//强连通片的编号
int N,M,cnt;
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
    for(int i = 1;i <= N;++i)
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
void dfs3(int x)
{
    visited[x] = true;
    ++cnt;//计数器
    for(auto &w : rG[x])
    {
        if(!visited[w])
          dfs3(w);
    }
}
//计算能被所有节点认可的节点个数
int CowsNum()
{
    int ans = 0;
    for(int i = 1 ;i <= N;++i)
    {    //属于缩点后拓扑序列的最后一类强连通片部分的节点
        if(sccNo[i] == sccflag)
        {
            cnt = 0;//计数器
            fill(visited.begin(),visited.end(),false);
            dfs3(i);//对该节点进行深度搜索，记录其能访问的节点个数
            if(cnt == N)
                ans++;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>M;
    G.resize(N+1);
    rG.resize(N+1);
    sccNo.resize(N+1);
    res.resize(N+1);
    visited = vector<bool>(N+1,false);
    while (M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    kosaraju();
    cout<<CowsNum()<<endl;
    return 0;
}
