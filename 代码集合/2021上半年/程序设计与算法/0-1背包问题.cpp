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
int dp_1[MAX_BAG];

int f(int i,int j)//对第i个物品进行决策，当前已经使用的体积为j
{
    if(i == N)
        return 0;
    if(j + w[i] > C)
        return f(i + 1,j);//不选
    return max(f(i+1,j),f(i + 1, j + w[i]) + v[i]);//可不选，可选
}
int fM(int i,int j)
{
    if(i == N)
        return 0;
    if(M[i][j] != -1)//已经计算过了，直接返回即可
        return M[i][j];
    if(j + w[i] > C)
        return M[i][j] = fM(i + 1,j);
    return M[i][j] = max(fM(i + 1,j), fM(i + 1,j + w[i]) + v[i]);
}
void fdp()
{
    for(int i = N-1 ;i >= 0; --i)
    {
        for(int j = 0;j <= C;++j)
        {
            if(j + w[i] > C)
            {
                dp[i][j] = dp[i + 1][j];
            }
            else 
            {
                dp[i][j] = max(dp[i + 1][j] ,dp[i + 1][j + w[i]] + v[i]);
            }
        }
    }
    printf("%d\n",dp[0][0]);
}
void fdp_1()
{
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j <= C - w[i];++j)
        {
            dp_1[j] = max(dp_1[j],dp_1[j + w[i]] + v[i]);
        }
    }
    printf("%d\n",dp_1[0]);
}
int main()
{
    scanf("%d%d",&N,&C);
    for(int i = 0;i < N;++i)
        scanf("%d%d",w + i, v + i);
   printf("%d\n",f(0,0));

   // memset(M, - 1, sizeof(M));
   // printf("%d\n",fM(0,0));
    
 //   fdp();

 //   fdp_1();

    return 0;
}
/*
4 5
1 2
2 4
3 4
4 5
*/