#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using Edge = pair<int,int>;//边的结构体 点，权重
using Activity = pair<int,int>;//活动的结构体  起点，终点
vector<vector<Edge> > G;//记录图信息
vector<int> d,f;//记录最早开始时间和最早结束时间
vector<Activity> ans;//记录结果的活动
vector<int> postOrder;//记录拓扑序列
vector<int> dis;//最长路径
vector<vector<int> > pre;//存储活动的前驱(构成一个反向活动图)
vector<bool> visited;//标志该节点是否访问过
bool isDAG; //是否为DAG
int N,M,ts;//N个点 M条边
//添加边信息
void addEdge(int x,int y,int c)
{
    G[x].push_back({y,c});
}
void dfs(int x)
{
    d[x] = ++ts;
    for(auto &i : G[x])
    {
        int c = i.first;
        if(d[c] == 0)
            dfs(c);
        else if(f[c] == 0 && d[c] < d[x])//判断是否有回路
        {
            isDAG = false;
            return;
        }
    }
    f[x] = ++ts;
    postOrder.push_back(x);//按照结束时间排序
}
void topSort()
{
    isDAG = true;
    dfs(0);
    if(isDAG)
    //在松弛每个节点之前一定要对逆拓扑序列进行反转
        reverse(postOrder.begin(),postOrder.end());
}
void relaxNode(int x)
{
    for(auto &e : G[x])
    {
        int c = e.first,w = e.second;
        if(dis[c] < dis[x] + w)
        {
            dis[c] = dis[x] + w;
            pre[c].clear();//首先要将之前c的所有前驱清除更新
            pre[c].push_back(x);
        }else if(dis[c] == dis[x] + w)//等于最长边则添加
        {
            pre[c].push_back(x);
        }
    }
}
void rDFS(int x)
{
    visited[x] = true;
    for(auto &w : pre[x])//节点X的每个前驱节点
    {
        if(!visited[w])
        {   
            rDFS(w);
        }
        ans.push_back({w,x});
    }
}
int main()
{
    cin>>N>>M;
    G.resize(N+2);
    d.resize(N+2);
    f.resize(N+2);
    dis.resize(N+2);
    pre.resize(N+2);
    visited.resize(N+2);
    while (M--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        addEdge(x,y,c);
        /*
        addEdge(0,y,0);//S节点的信息
        addEdge(x,N+1,0);//T节点的信息
        */
       addEdge(0,x,0);//S指向所有起点 权重为0
       addEdge(y,N+1,0);//所有终点指向T  权重为0
    }
    topSort();//判断是否为DAG
    if(!isDAG)
        cout<<0<<endl;
    else 
    {
        fill(dis.begin(),dis.end(),0 - 0x3f3f3f3f);
        dis[0] = 0;//S节点的最长路径置为零
        for(auto &w : postOrder)//松弛每个节点
            relaxNode(w);
        cout<<dis[N+1]<<endl;//输出最长路径
        fill(visited.begin(),visited.end(),false);
        rDFS(N+1);//从T节点开始反向深搜得到关键活动的路径
        //对输出结果进行排序
        //sort(ans.begin(),ans.end(),[](auto & a1,auto & a2){if(a1.first == a2.first)return a1.first < a2.first;return a1.second > a2.second;});
        //任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反
        sort(ans.begin(),ans.end(),[](auto & a1,auto & a2){return a1.first == a2.first ? a1.second > a2.second : a1.first < a2.first;});
        for(auto &w : ans)
        {
            if(w.first == 0 || w.second == N+1)//如果起点是S或者终点是T则跳出此次循环
                continue;
            cout<<w.first<<"->"<<w.second<<endl;
        }
    }
    
    return 0;
}
