#include<iostream>
#include<vector>
#include<set>
#include<numeric>
#include<algorithm>
using namespace std;
int N,K,cnt = 0;
vector<int> pre;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x),ny = find(y);

    if(nx == ny)
        return;

    --cnt;
    if(nx < ny)
    {
        pre[ny] = nx;
    
    }
    else if(nx > ny)
    {
        pre[nx] = ny;
        
    }
}
int main()
{
    cin>>N;
    set<int> st;
    pre.resize(10005);

    iota(pre.begin(),pre.end(),0);
    for(int i = 0;i < N;++i)
    {
        cin>>K;
        int t;
        cin>>t;
        st.insert(t);
        for(int j = 1;j < K;++j)
        {
            int id;
            cin>>id;
            st.insert(id);
            un(t,id);
        }
    }
    cout<<st.size()<<" "<<(st.size() + cnt)<<endl;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<((find(x) == find(y)) ? "Y\n" : "N\n" );
    }
    return 0;
}