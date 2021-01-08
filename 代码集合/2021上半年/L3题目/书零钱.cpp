#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
int N,M;
int a[10010];

set<int> mp;
vector< set<int> > result;
void dfs(int x,int sum)
{
    if(x > N)return ;
    if(sum == M){
        result.push_back(mp);
        return;
    }
    mp.insert(a[x]);
    dfs(x+1,sum+a[x]);
    mp.insert(a[x]);
    dfs(x+1,sum);
    
}
int main()
{
 
    cin>>N>>M;
    for(int i = 0;i < N;++i)
        cin>>a[i];
    dfs(0,0);
    for(auto con : result){
        for(auto i : con)
        {
            cout<<i;
        }cout<<endl;
    }
    cout<<result.size()<<endl;
    return 0;
}