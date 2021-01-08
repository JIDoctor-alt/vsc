#include<iostream>

using namespace std;
int a[1005];
int N,S;
bool dfs(int i ,int sum)
{
    if(sum == S)return true;

    if(i >= N)return false;

    return dfs(i+1,sum)||dfs(i+1,sum+a[i]);
}
int main()
{
    cin>>N>>S;
    for(int i = 0;i < N;i++)
        cin>>a[i];
    cout<<(dfs(0,0) ? "YES" : "NO")<<endl;
    return 0;
}