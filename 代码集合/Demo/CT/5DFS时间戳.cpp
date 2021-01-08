#include<iostream>
#include<vector>
using namespace std;
vector<int> d,f;//开始时间，结束时间
vector<vector<int> > g;
vector<int> postOrder;
int N,M,ts;
void dfs(int x)
{
    d[x] = ++ts;
    for(auto w : g[x])
    {
        if(d[w] == 0)
            dfs(w);
    }
    f[x] = ++ts;
    postOrder.push_back(x);
}
int main()
{
    cin>>N;//顶点和边

    g.resize(N);
    d.resize(N);
    f.resize(N);
    M = N;
    while(M--)
    {
        /*int x,y;
        cin>>x>>y;
        g[x].push_back(y);*/
        int uid,k;
        cin>>uid>>k;
        while(k--)
        {
            int vid;
            cin>>vid;
            g[uid].push_back(vid);
        }
    }
    for(int i = 0;i < N;++i)
    {
        if(d[i] == 0)
            dfs(i);
    }
    for(int i = 0;i < N;++i)
       cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;

    //拓扑排序
    /*for(int i = N-1;i >= 0;--i)
        cout<<postOrder[i]<<" ";
    cout<<endl;
    */

    return 0;
}
/*Test  13个结点 15条边
13
15
2 3
0 6
0 1
2 0
11 12
9 12
9 10
9 11
3 5
8 7
5 4
0 5
6 4
6 9
7 6
*/