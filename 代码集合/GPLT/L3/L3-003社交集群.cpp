#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
int pre[1005];
int n,k,cnt = 0;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x), ny = find(y);
    if(nx == ny)
        return;
    if(nx < ny){
         pre[ny] = nx;
    }
    else{
        pre[nx] = ny;
    } 
        
    --cnt;
}
bool cmp(int &a,int &b)
{
    return a > b;
}
int main()
{
    iota(pre,pre + 1005,0);
    cin>>n;

    vector<vector<int> > peo = vector<vector<int> >(1005);
    for(int j = 1;j <= n;++j)
    {
        int k;
        scanf("%d:",&k);

        for(int i = 0;i < k;++i)
        {
            int id;
            cin>>id;

            peo[id].push_back(j);
        }
    }
    for(int i = 1;i < 1005;++i)
    {
        if(peo[i].size() == 0)
            continue;

        int t = peo[i][0];
        for(int j = 1;j < peo[i].size();++j)
        {
            int w = peo[i][j];
            un(t,w);
        }
    }

    vector<int> res(n+1,0);

    for(int i = 1;i <= n;++i)
    {
        int id = find(i);

        ++res[id];

    }
    vector<int> ans;

    for(auto w : res)
    {
        if(w != 0)
            ans.push_back(w);
    }

    sort(ans.begin(),ans.end(),cmp);

    cout<<(n + cnt)<<"\n";

    cout<<ans[0];
    for(int i = 1;i < ans.size();++i)
        cout<<" "<<ans[i];

    return 0;
}