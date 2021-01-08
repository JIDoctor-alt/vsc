#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_imal = 55;
struct Edge
{
    int from, to ,w ;
};
vector<Edge> edge;
int pre[55];
int N,M;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
bool cmp(Edge &e1 , Edge &e2)
{
    return e1.w < e2.w;
}
int kruskal()
{
    //sort(edge.begin(),edge.end(),[](auto &e1,auto &e2){return e1.w < e2.w;});
    sort(edge.begin(),edge.end(),cmp);
    int ans = 0, cnt = 0;
    for(auto &i : edge)
    {
        int x = i.from, y = i.to, w = i.w;
        x = find(x);
        y = find(y);
        if(x == y)
            continue;
        ans += w;
        pre[x] = y;
        if(++cnt == N -1 )
            break;
    }
    return cnt == N - 1 ? ans : -1;

}
int main()
{
    while (cin>>N && N)
    {
        cin>>M;
        edge.clear();
        for(int i = 0;i < M;++i)
        {
            int x,y, c;
            cin>>x>>y>>c;
            edge.push_back({x,y,c});
        }
        iota(pre, pre + MAX_imal, 0);
        cout<<kruskal()<<endl;
    }
    return 0;
}