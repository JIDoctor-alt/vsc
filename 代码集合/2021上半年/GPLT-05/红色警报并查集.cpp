#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ndge = pair<int,int>;
int N,M,K;
vector<int> postNum;
vector<bool> lost;
vector< vector<int> > g;
vector<bool> visited;
vector<ndge> de;

vector<int> pre;
int  find(int x)
{
    return x == pre[x] ? x : find(pre[x]);
}
void un(int a,int b)
{
    int na = find(a);
    int nb = find(b);
    if(na != nb)
        pre[na] = nb;
}
int getNum()
{
    //自增数组，初始化父结点
    //iota(pre.begin(),pre.end(),0);
    for(int i = 0;i < N;++i)
        pre[i] = i;
    /*for(int i = 0;i < N;i++)
    {   
        for(auto w : g[i])
        {
            if(!lost[w]&&!lost[i])
                un(i,w);
        }
    }*/
    for(int i = 0;i < N;++i)
        if(!lost[de[i].first]&&!lost[de[i].second])
            un(de[i].first,de[i].second);
    int ans = 0;
    for(int i = 0;i < N;++i)
    {
        if(!lost[i]&&pre[i] == i)ans++;
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    g.resize(N);
    pre.resize(N);
    visited.resize(N);
    lost = vector<bool>(N,false);

    de.resize(M);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        de[i].first = x,de[i].second = y;
    }
    cin>>K;
    postNum.push_back(getNum());
    while(K--)
    {
        int num;
        cin>>num;
        lost[num] = true;
        postNum.push_back(getNum());
        if(postNum.back() > postNum[postNum.size()-2])
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        else
            cout<<"City "<<num<<" is lost."<<endl;

        if(postNum.back() == 0)
            cout<<"Game Over."<<endl;
    }
    return 0;
}