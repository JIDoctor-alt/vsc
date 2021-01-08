#include<iostream>
#include<set>
#include<numeric>
using namespace std;
int N,cnt = 0;
int pre[10005];
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x), ny = find(y);
    if(nx == ny)
        return;
        
    if(nx < ny)
        pre[ny] = nx;
    else 
        pre[nx] = ny;
    cnt++;
    
}
int main()
{
    iota(pre , pre + 10005,0);
    cin>>N;
    set<int> peo;
    for(int i = 0;i < N;++i)
    {
        int K;
        cin>>K;
        int t;
        cin>>t;
        K--;
        peo.insert(t);
        while(K--)
        {
            int id;
            cin>>id;
            peo.insert(id);
            un(t,id);
        }
    }
    cout<<peo.size()<<" "<<(peo.size() - cnt)<<endl;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(find(a) == find(b) ? "Y\n" : "N\n");
    }
    return 0;
}