#include<iostream>
#include<cstring>
#include<algorithm>

#define INF 0x3f3f3f3f
using namespace std;
struct H{
    int x1,x2;
    int h;
    bool operator<(const H & n){
        return h < n.h;
    }
}stu[1100];
int dp[1100][2];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,X,Y,MAX;
        cin>>N>>X>>Y>>MAX;
        
        for(int i = 1;i <= N;i++)
            cin>>stu[i].x1>>stu[i].x2>>stu[i].h;
            sort(stu+1,stu+N+1);
        stu[0].x1 = -INF;
        stu[0].x2 = INF;
        stu[0].h = 0;
        stu[N+1].x1 = X;
        stu[N+1].x2 = X;
        stu[N+1].h = Y;
        memset(dp,0,sizeof(dp));

        for(int i = 1;i <= N+1;i++){
            //是否可以向下跳
            int lfalg = 0,rfalg = 0;
            //高度允许
            for(int j = i-1;j >= 0&&(stu[i].h - stu[j].h) <= MAX;j--)
            {
                if(stu[i].x1 >= stu[j].x1 && stu[i].x1 <= stu[j].x2){
                     lfalg = 1;//向下跳
                     if(j ==0 )//地面
                        dp[i][0] = stu[i].h;
                    else 
                     dp[i][0] = stu[i].h - stu[j].h + min(dp[j][0] + stu[i].x1 - stu[j].x1,dp[j][1] + stu[j].x2- stu[i].x1);
                    break;
                }
            }
            if(lfalg == 0)dp[i][0] = INF;

            for(int j = i-1;j >= 0&& stu[i].h - stu[j].h <= MAX ;j--)
            {
                if(stu[i].x2 >= stu[j].x1&&stu[i].x2 <= stu[j].x2 )
                {
                    rfalg = 1;

                    if(j==0)
                        dp[i][1] = stu[i].h;
                    else
                        dp[i][1] = stu[i].h - stu[j].h + min(dp[j][0] + stu[i].x2-stu[j].x1,dp[j][1] + stu[j].x2 - stu[i].x2 );
                    break;
                }
            }
            if(rfalg == 0)dp[i][1] = INF;
        }
        cout<<min(dp[N+1][0],dp[N+1][1])<<endl;
        

    }
    return 0;
}