#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N,M,K,Np;
vector<bool> flag;
vector< vector<int> > g;

vector<int> pre;

int find(int x)
{
    return x == pre[x] ? x : find(pre[x]);
}
bool unite(int nx ,int ny)
{
    int ax = find(nx);
    int ay = find(ny);
    if(ax != ay)
       return false;
    return true;
}
void init()
{
    for(int i = 0;i <= N;++i)
        pre[i] = i;
}
bool check()
{
    init();
   for(int i = 1;i <= N;++i)
   {
       if(!flag[i])
       {
             for(auto w : g[i])
             {
                if(!flag[w]){
                     if(!unite(w,i))
                        return false;
                }     
            }
       }       
   } 
    return true;
}
int main()
{
    cin>>N>>M;
    
    g.resize(N+1);
    flag.resize(N+1);
    pre.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>K;
    while (K--)
    {
        fill(flag.begin(),flag.end(),false);
        cin>>Np;
        while (Np--)
        {
            int num;
            cin>>num;
            flag[num] = true;
        }   
        cout<<(check() ? "YES\n":"NO\n");
    }
    
    
    return 0;
}