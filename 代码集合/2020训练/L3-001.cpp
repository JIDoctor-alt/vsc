#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
int dp[10005],price[10005];
bool visited[10005][10005];
void judge()
{
    for(int i = 1;i <= N;++i)
    {
        for(int j = M;j >= price[i]; --j)
        {
            if(dp[j] <= dp[j - price[i]] + price[i])
            {
                visited[i][j] = true;
                dp[j] = dp[j - price[i]] + price[i];
            }
        }
    }
}
int main()
{
    memset(visited,sizeof(visited),false);
    cin>>N>>M;
    for(int i = 1;i <= N;++i)
        cin>>price[i];

    sort(price + 1,price + N + 1,[](auto &e1,auto &e2){return e1 >e2;});

    judge();
    
    if(dp[M] != M)
    {
        printf("No Solution\n");
    }
    else
    {
        int cnt = 0,pr = M,index = N;
        while(pr > 0)
        {
            if(visited[index][pr])
            {
                if(cnt != 0)
                    printf(" ");
                cout<<price[index];
                pr -= price[index];
                ++cnt;
            }
            --index;
        }
    }
    
    return 0;
}