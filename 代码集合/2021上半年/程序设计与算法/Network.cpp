#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//vector<vector<int> > G;

//vector<int> d;
//vector<int> low;
//vector<bool> isAcsaulation;
vector<int> G[105];
int d[105],low[105];
bool isAcsaulation[105];
int N;
int timestamp;
int getInt(string &str)
{
    return stoi(str);
}
vector<int> getEdge(string &str)
{
    int i = 0,j = i;
    vector<int> ans;
    while(true)
    {
        while (i < str.length() && str[i] == ' ')
            ++i;
        j = i;//查找连续数字的个数
        while (j < str.length() && str[j] != ' ')
            ++j;
        ans.push_back(stoi(str.substr(i,j-i)));//每一行的数字
        i = j;//查找第二个数字
        if( i >= str.length())//判断是否查找结束
            break;
    }
    return ans;
}
void dfs(int x,int pa)
{
    low[x] = d[x] = ++timestamp;
    int child = 0;
    for(auto &w : G[x])
    {
        if(d[w] == 0)
        {
            ++child;
            dfs(w,x);
            low[x] = min(low[x],low[w]);
            if(pa != -1 && low[w] >= d[x])
                isAcsaulation[x] = true;
        }
        else if(w != pa && d[w] < d[x])
              low[x] = min(low[x],d[w]);
    }
    if(pa == -1 && child > 1)
        isAcsaulation[x] = true;
}
int getIsAcstrculation(){
        timestamp = 0;//初始化时间戳
        //d.resize(N+1);
        //low.resize(N+1);
        //isAcsaulation.resize(N+1);
  //  fill(isAcsaulation.begin(),isAcsaulation.end(),false);
    for(int i = 0;i < 105;++i)
    {
        d[i] = 0;
        low[i] = 0;
        isAcsaulation[i] = false;
    }
    for(int i = 1;i <= N;++i)
    {
        if(d[i] == 0)
            dfs(i,-1);
    }
    int ans = 0;
    for(int i = 1;i <= N;++i)
        if(isAcsaulation[i])
            ++ans;
    return ans;
}
int main()
{
    while (true)
    {
        string str;
        getline(cin,str);

        N = getInt(str);
        if(N == 0)//最后一块信息为0
            break;

        
        //每次测试都要初始化
       // G.resize(N+1);

        while(true)//该块的边信息
        {
            getline(cin,str);
            vector<int> edge = getEdge(str);
            
            //建立图信息
            for(int i = 1;i < edge.size();++i)//注意从1开始
            {
               G[edge[0]].push_back(edge[i]);
               G[edge[i]].push_back(edge[0]);
            }
            //注意每一块的结束符号
            if(edge.size() == 1&&edge[0] == 0)
                break;
        }
        cout<<getIsAcstrculation()<<endl;
        for(int i = 0;i < 105;++i)
            G[i].clear();
    }
    
    return 0;
}