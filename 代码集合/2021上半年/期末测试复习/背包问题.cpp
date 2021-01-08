#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_BAG = 1005;
int v[MAX_BAG],w[MAX_BAG];
int N,C;
int M[MAX_BAG][MAX_BAG];
int dp[MAX_BAG][MAX_BAG];
int dp1[MAX_BAG];
int f(int  i,int j)
{
    if(i == N)
        return 0;
    if(j + w[i] > C)
        return f(i + 1,j);
    return max(f(i + 1,j),f(i + 1,j + w[i]) + v[i]);
}
int fM(int i,int j)
{
    if(i == N)
        return 0;
    if(M[i][j] != -1)
        return M[i][j];
    if(j + w[i] > C)
        return M[i][j] = fM(i + 1,j);
    return M[i][j] = max(fM(i + 1,j),fM(i + 1,j + w[i]) + v[i]);
}
void fdp()
{
    for(int i = N;i >= 0;i--)
    {
        for(int j = 0;j <= C;++j)
        {
            if(j + w[i] > C)
            {
                dp[i][j] = dp[i + 1][j];
            }
            else 
            {
                dp[i][j] = max(dp[i+1][j],dp[i + 1][j + w[i]] + v[i]);
            }
        }
    }
    printf("%d\n",dp[0][0]);
}
int main()
{
    scanf("%d%d",&N,&C);
    for(int i = 0;i < N;++i)
        scanf("%d%d",w+i,v+i);
    fdp();
}