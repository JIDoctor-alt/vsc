#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int N;
double r,Z;
vector<vector<int> > g;
map<int,int> nubi_n;
map<int,double> nubi_beishu;

void dfs(int x,int n)
{
    nubi_n[x] = n;
    for(auto w : g[x])
      //  if(!nubi_n.count(w))
      if(nubi_n.find(w) == nubi_n.end())
            dfs(w,n+1);
    
}
int main()
{
    cin>>N>>Z>>r;
    r = 1 - r/100;
    g.resize(N);
    for(int  i = 0;i < N;i++)
    {
        int k;
        cin>>k;
        if(k)
        {
            while(k--)
            {
                int id;
                cin>>id;
                g[i].push_back(id);
            }
        }
        else
        {
            int num;
            cin>>num;
            nubi_beishu[i] = num;
        }
    }
    dfs(0,0);
    double ans = 0;
    for(auto i : nubi_beishu)
    {
        int n = i.first;
        int s = i.second;
        ans += Z * pow(r,nubi_n[n]) * s;
    }
    cout<<(int)ans<<endl;
    return 0;
}