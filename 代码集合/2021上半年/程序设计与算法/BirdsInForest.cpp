#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
const int MAX_V = 10010;
int pa[MAX_V];
vector<vector<int> > picture;
int N,K,Q;
int maxid = 0 , cnt = 0;
int find(int x)
{
    return pa[x] == x  ? x : find(pa[x]);
}
void un(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx != ny)
    {
     pa[nx] = ny;
     --cnt;
    }  
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    iota(pa,pa + MAX_V,0);
    for(int i = 0;i < N;++i)
    {
        cin>>K;
        int t;
        cin>>t;
        maxid = max(t,maxid);
        while (--K)
        {
            int id;
            cin>>id;
            maxid = max(id,maxid);
            //picture[i].push_back(id);
            un(id,t);
        }
    }
    cout<<maxid+cnt<<" "<<maxid<<endl;
    cin>>Q;
    while (Q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(find(a) == find(b) ? "Yes\n" : "No\n");
    }
    
}