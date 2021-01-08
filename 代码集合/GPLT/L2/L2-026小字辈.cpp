#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
int N,root,max_deep = 1;
vector<vector<int> > G;
vector<int> res;
void judge()
{
  
    queue<pii> pq;
    pq.push({1,root});

    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();

        int x = v.second, deep = v.first;

        if(deep > max_deep)
        {
            max_deep = deep;
            res.clear();
            res.push_back(x);
        }else if(max_deep == deep){
            res.push_back(x);
        }

    
        for(auto &e : G[x])
        {
            pq.push({deep + 1,e});
        }
    }
}
int main()
{
    cin>>N;
    G.resize(N+1);
   // int root;
    for(int i = 1;i <= N;++i)
    {
        int pre;
        cin>>pre;

        if(pre != -1)
            G[pre].push_back(i);
        else 
            root = i;
    }
    judge();

    cout<<max_deep<<endl;

    cout<<res[0];
    for(int i = 1;i < res.size();++i)
    {
        cout<<" "<<res[i];
    }
    cout<<"\n";
    return 0;
}