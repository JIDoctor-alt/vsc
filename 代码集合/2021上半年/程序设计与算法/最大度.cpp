#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > g;
vector<int> indegree;
int N,M;
int main()
{
    cin>>N>>M;
    g.resize(N);
    indegree.resize(N);
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        indegree[x]++;
        indegree[y]++;
    }
    cout<<*max_element(indegree.begin(),indegree.end())<<endl;
    cout<<*min_element(indegree.begin(),indegree.end())<<endl;
    return 0;
}