#include<iostream>
#include<cstring>

using namespace std;
char s[100];
int dp[100][100];
int num[100][100];
int v(int m,int n){
    if(m == 0)
        return num[1][n];//从第一个数到最后一个数字所组成的数
    else if(n < m+1)
        return 0x3f3f3f3f;
    else{
        int min1 = 0x3f3f3f3f;
        for(int i = m;i <= n-1;i++)//最后一个加号放的位置
            min1 = min(v(m-1,i)+num[i+1][n],min1);
            return min1;
    }
}
int main(){
    int m;
    int n;
    while(cin>>m>>n){
       // int k = n.length();
       int d = n;
       int k = 0;
       while(d){
           d/=10;
           k++;
       }
        for(int i = k-1;i>=0;i--){
            s[i] = n%10 +'0';
            n/= 10;
        }
        //从第j个数开始到第i个数所组成的的数 下标从1开始
        //而存储数字的下标从零开始
        for(int i = 1;i <= k;i++){
            num[i][i] = s[i-1]-'0';
            for(int j = i+1;j<=k;j++){
                num[i][j] = num[i][j-1]*10 + (s[j-1] - '0');
            }
        }

        memset(dp,0x3f,sizeof(dp));
        //dp是i个加法插入的j个数中
        for(int i = 1;i <= k;i++)
        //i个数
            dp[0][i] = num[1][i];//当前没有加号时 0个加号i个数组
        
        //m个加号
        for(int i = 1;i <= m;i++){
            //k个数
            for(int j = i;j <= k;j++){
                //最后一个加号放在i个数字的右边 
                for(int l = i;l <= j;l++)
                //第i个加号，j个数
                    dp[i][j] = min(dp[i][j],dp[i-1][l]+num[l+1][j]);
            }
        }

        cout<<dp[m][k]<<endl;
   //     cout<<v(m,k)<<endl;
    }
}