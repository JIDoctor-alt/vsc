#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_W = 10005;
bool visited[MAX_W][MAX_W];
int dp[MAX_W],C[MAX_W],N,M;
void fdp()
{
    for(int i = 1;i <= N;++i){
        for(int j = M;j >= C[i];--j){
            if(dp[j] <= dp[j - C[i]] + C[i]){
                visited[i][j] = true;
                dp[j] = dp[j - C[i]] + C[i];
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 1;i <= N;++i){
        cin>>C[i];
    }
    sort(C + 1,C + N + 1,[](auto &a,auto &b){return a > b;});
    fdp();
    if(dp[M] != M){
        cout<<"No Solution";
    }
    else{
        int price = M,flag = 0,index = N;
        while(price > 0)
        {
            if(visited[index][price])
            {
                if(flag == 1)
                    cout<<" ";
                if(flag == 0)
                    flag = 1;
                cout<<C[index];
                price -= C[index];
            }
            index--;
  
        }
        cout<<endl;
    }
    return 0;
}