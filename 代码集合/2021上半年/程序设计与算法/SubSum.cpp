#include<iostream>
using namespace std;
int N,S;
int a[105];
bool dp[105][50005];
//注意下标从零开始
bool dfs1(int i,int sum)
{
    if(sum == S)
        return true;

    if(i >= N)
        return false;
    if(sum > S)
         return false;
    return dfs1(i+1,sum + a[i]) || dfs1(i+1,sum);
}
bool dfs2(int i,int sum)
{
    //边界条件
    if(sum == 0)
        return true;
        //剪枝
    if(i < 1)
        return false;
    if(sum < 0)
        return false;
        //从后向前递归，选中，不选的两种情况
    return dfs2(i-1,sum - a[i])||dfs2(i-1,sum);
}
void solve1()
{
    ///把每一行的最后一列初始化为true ,剩下的直接循环操作即可
    //最后要看 dp[0][0]
    for(int i = 0;i <= N;i++)
        dp[i][S] = true;
        //从最后一个行开始 即 第三行
    for(int i = N-1;i >= 0;--i)
    {
        for(int j = 0;j < S;j++)
        {
            //从左向右扫一遍就ok了！！！
            if(j + a[i] < 50005)//下一行或者 下一行的a[i]列
                dp[i][j] = dp[i + 1][j] || dp[i+1][j + a[i]];
        }
    }
}
void solve2()
{
    //模拟dfs2()
    //将第一列初始化为true，当减称0时说明正确
    for(int i = 0;i <= N;++i)
        dp[i][0] = true;
        //返回的是N，S。从后向前递归的化简
    for(int i = 1;i <= N;++i)
    {
        for(int j = 0;j <= S;++j)
        {

            if(j - a[i] >= 0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i]];
        }
    }
}
int main()
{
    cin>>N>>S;
   for(int i = 0;i < N;++i)
       cin>>a[i];
    bool f = dfs1(0,0);
    //    bool f = dfs2(N,S);
    cout<<(f ? "Yes" : "No")<<endl;
/*
    for(int i = 1;i <= N;++i)
        cin>>a[i];
   // solve2();
  // solve1();
    cout<<(dp[N][S] ? "Yes" : "No")<<endl;*/
    return 0;
}
//dfs(i,sum) = dfs(i+1,sum + a[i]) || dfs(i+1,sum);
//如果i为3 dfs(3,sum) = dfs(4,sum + 1)|| dfs(i+1,sum);