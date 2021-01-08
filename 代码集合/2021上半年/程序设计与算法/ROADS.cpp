#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K,N,R;
struct Road
{
    int d,l,t;
};
//邻接表：存储i城市的邻接点信息
vector<vector<Road> > cityMap(110);
//最短路径
int minLen = 1<<30;
int totalLen;//当前的路径长度
int totalCost;//当前的花费
int visited[110];//该结点是否被访问
int minL[110][10100];//minL[i][j]表示从起点到i点花费j块钱时所走的最短路径长度
void DFS(int s)//从点S向N点行走​
{
    if(s == N)//边界条件​
    {//选择最短路径​
        minLen = min(minLen,totalLen);
        return;
    }//查看S的每个邻接点​
    for(int i = 0;i < cityMap[s].size();++i)
    {
        int d = cityMap[s][i].d;
        if(!visited[d])
        { 
            int cost = totalCost + cityMap[s][i].t;
            if(cost > K)//路费超过了自己的钱​
                continue;
              //到该点的路径大于之前走的最短路径或者大于到该点花销为cost时的最短路径（跳过）​
            if(totalLen + cityMap[s][i].l >= minLen
            || totalLen + cityMap[s][i].l >= minL[d][cost])
                continue;
            //可行 总路径 和 总花销 加上到这个点的 路径 和 花销
            totalLen += cityMap[s][i].l;
            totalCost += cityMap[s][i].t;
            minL[d][cost] = totalLen; //更新 到d点花销为cost 的最短路径
            visited[d] = 1;
            DFS(d);
            //以上走法判断完成之后恢复现场信息（进行下一种走法）
            visited[d] = 0;
            totalCost -= cityMap[s][i].t;
            totalLen -= cityMap[s][i].l;
        }
    }
}
int main()
{
    cin>>K>>N>>R;
    for(int i = 0;i < R;++i)
    {
        int s;
        Road r;
        cin>>s>>r.d>>r.l>>r.t;
        if(s != r.d)
            cityMap[s].push_back(r);
    }//将minL初始化为无穷大
    for(int i = 0;i < 110; ++i)
        for(int j = 0;j < 10100;++j)
            minL[i][j] = 1<<30;
   //这个minL数组不能用下面的方法
   // memset(minL,1<<30,sizeof(minL));
    memset(visited,0,sizeof(visited));
    totalLen = 0;
    totalCost = 0;
    visited[1] = 1;//设置起点为已访问
    minLen = 1<<30;
    DFS(1);
    cout<<(minLen != 1 << 30 ? minLen : -1)<<endl;
    return 0;
}