#include<iostream>
#include<vector>
using namespace std;
//存图（任务的依赖关系）
vector< vector<int> > g;
//（相等于开始搜索的）开始时间，结束时间
vector<int> discoverTime,finishTime;
//任务的最早开始实际，最早结束时间
vector<int> EarliestStartTime,EarliestFinishTime;
//任务的持续时间
vector<int> durationTime;
//关键路径
vector<int> criticalPath;
int N,M;
//时间戳
int timestamp;

void DFS(int x)
{
   
    discoverTime[x] = ++timestamp;
    criticalPath[x] = -1;
    //x的前驱任务w完成之后才可以进行x
    //所有的依赖任务都访问完了，结果就确定了 最晚完成时间也就确定了
    for(auto w : g[x])
    {
        //没有访问过就深度搜索
        if(discoverTime[w] == 0)
            DFS(w);
        //前驱任务的最早结束时间比它的最早开始时间要晚（它的最早开始时间要更新）
        if(EarliestFinishTime[w] >= EarliestStartTime[x])
        {
            EarliestStartTime[x] = EarliestFinishTime[w];
            //首先要完成任务w才能完成任务x
            criticalPath[x] = w;
        }
    }
    //最早结束时间 = 最早开始时间 + 持续时间
    EarliestFinishTime[x] = EarliestStartTime[x] + durationTime[x];
    finishTime[x] = ++timestamp;
}
int main()
{
    //N个结点
    cin>>N;
    g.resize(N);
    durationTime.resize(N);
    discoverTime.resize(N);
    finishTime.resize(N);
    EarliestStartTime.resize(N);
    EarliestFinishTime.resize(N);
    criticalPath.resize(N);
    //每个结点的持续时间（权重）
    for(int i = 0;i < N;++i)
        cin>>durationTime[i];
    cin>>M;
    while(M--)
    {
        int x,y;
        //任务x完成之后才能进行任务y
        cin>>x>>y;
        //g[x].push_back(y);错误
        g[y].push_back(x);
    }

    for(int i = 0;i < N;++i)
    {
        if(discoverTime[i] == 0)
            DFS(i);
    }
    cout<<"id  :               ";
    for(int i = 0;i < N;++i)
        cout<<i<<"\t";
    cout<<endl;
    cout<<"EarliestStartTime:  ";
    for(int i = 0;i < N;++i)
        cout<<EarliestStartTime[i]<<"\t";
    cout<<endl;
    cout<<"EarliestFinishTime: ";
    for(int i = 0;i < N;++i)
        cout<<EarliestFinishTime[i]<<"\t";
    cout<<endl;
    cout<<"pre:                ";
    for(int i = 0;i < N;++i)
        cout<<criticalPath[i]<<"\t";
    cout<<endl;
    return 0;
}
