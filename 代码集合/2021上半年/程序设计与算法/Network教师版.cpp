#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int MAX  = 105;
vector<int> g[MAX];
int d[MAX],low[MAX],ts;
bool isArticulation[MAX];
int N;
//对每一行交换机相连的信息进行记录（该交换机的编号 相连的交换机编号1  相连的交换机编号2。。。。
vector<int> getAllInt(string &str)
{
    vector<int> ans;
    int i = 0,j = i;
    while(true)
    {
        while(i < str.length() && str[i] == ' ')
            ++i;
        j = i;//注意这里的j从第一个不为空格的下标开始
        while(j < str.length() && str[j] != ' ')
            ++j;
        ans.push_back(stoi(str.substr(i,j - i)));
        i = j;//这个时候j下标对应的元素为空格
        if( i >= str.length())//整个字符串查找完毕
            break;
    }
    return ans;
}
int getInt(string &str)
{
    return stoi(str);
}
void dfs(int x,int pa)
{
    d[x] = low[x] = ++ts;
    int child = 0;
    for(auto i : g[x])
    {
        if(d[i] == 0)
        {
            ++child;
            dfs(i,x);
            low[x] = min(low[x],low[i]);//所连的开始时间最早的点
            if(pa != -1 && low[i] >= d[x])//不是根节点
                isArticulation[x] = true;
        }
        else if(i != pa && d[i] < d[x])
            low[x] = min(low[x],d[i]);//所连的开始时间最早的点
    }
    if(pa == -1 && child > 1)//根节点的情况
        isArticulation[x] = true;
}
int articulationCnt()
{
    //初始化d,low,isArticulation,ts
    for(int i = 0;i < MAX;++i)
    {
        d[i] = low[i] = 0;
        isArticulation[i] = false;
    }
    ts = 0;

    for(int i = 1;i <= N;++i)
    {
        if(d[i] == 0)
            dfs(i,-1);
    }//计算割点的数量
    int ans = 0;
    for(int i = 1; i <= N;++i)
        if(isArticulation[i])
            ++ans;
    return ans;
}
int main()
{
   while(true)
   {
       string str;
       getline(cin,str);//N个交换机
       N = getInt(str);
       if(N == 0)//最后一块有0个交换机
            break;
            
        while(true)//计算该块中每一行的连接信息
        {
            getline(cin,str);
            vector<int> v = getAllInt(str);
            for(int i = 1;i < v.size();++i)
            {
                g[v[0]].push_back(v[i]);
                g[v[i]].push_back(v[0]);
            }
            if(v.size() == 1 && v[0] == 0)//每一块的最后一行为0，该块信息输入的结束符号
                break;
        }
        cout<<articulationCnt()<<endl;
        for(int i = 0;i < MAX;++i)//清空图信息，便于下次操作
            g[i].clear();
   }
    return 0;
}