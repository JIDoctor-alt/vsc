#include<iostream>
#include<set>
#include<numeric>
#include<algorithm>
using namespace std;
const int MAX_STU = 10005;
int pre[MAX_STU];
int cnt = 0,N;
///譬如a[1]=3,a[3]=2直接变成a[1]=2这样成了很多时间 ，给自己的代码小改一下，A了
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx > ny)
    {pre[ny] = nx;--cnt;}
    else if(nx < ny){
        pre[nx] = ny;
        --cnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    iota(pre , pre + MAX_STU,0);
    cin>>N;
    set<int> st;
    for(int i = 0;i < N;++i)
    {
        int K;
        cin>>K;
        int t;
        cin>>t;
        st.insert(t);
        while(--K)
        {
            int id;
            cin>>id;
            st.insert(id);
            un(t,id);
        }
    }
    int ans = st.size();
    cnt += ans;
    cout<<ans<<" "<<cnt<<endl;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        if(find(a) == find(b))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}