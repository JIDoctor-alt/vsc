#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cstring>
using namespace std;
using pii = pair<int,int>;
//注意边的集合分配大小为M，另外并查集中的 pre[nx] = ny; 不是nx = pre[ny];
vector<pii> ndge;
vector<bool> lost;
vector<int> conentNum;
vector<int> pre;
int N,M,K;
int find(int x)
{
    return x == pre[x] ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx != ny)
        pre[nx] = ny;
}
int getCity()
{
    iota(pre.begin(),pre.end(),0);
    for(int i = 0;i < M;++i){
        int a = ndge[i].first;
        int b = ndge[i].second;
        if(!lost[a]&&!lost[b])
            un(a,b);
    }
    int ans = 0;
    for(int i = 0;i < N;++i)
        if(!lost[i]&&pre[i]==i)
            ans++;
    return ans;
}
int main()
{
    cin>>N>>M;
    lost.resize(N);
    //存储M条边
    ndge.resize(M);
    pre.resize(N);
    fill(lost.begin(),lost.end(),false);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        ndge[i].first = x;
        ndge[i].second = y;
    }
    conentNum.push_back(getCity());
    cin>>K;
    while (K--)
    {
        int num;
        cin>>num;
        lost[num] = true;
        conentNum.push_back(getCity());
        if(conentNum.back() > conentNum[conentNum.size()-2])
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        else 
            cout<<"City "<<num<<" is lost."<<endl;
        if(conentNum.back() == 0)
            cout<<"Game Over."<<endl;
    }
    return 0;
}