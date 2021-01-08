#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<int> degree;
int V,E;
int main()
{
    cin>>V>>E;
    G.resize(V);
    degree.resize(V);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        ++degree[x];
        ++degree[y];
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout<<*max_element(degree.begin(),degree.end())<<endl;
    cout<<*min_element(degree.begin(),degree.end())<<endl;
    return 0;
}