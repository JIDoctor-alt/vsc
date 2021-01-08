#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int MAXSum(int i,int j)
{
    if(i == n)
        return D[i][j];
    int x = MAXSum(i + 1,j);
    int y = MAXSum(i + 1,j + 1);
    return max(x,y) + D[i][j];
}
int main()
{
    int i,j;
    cin>>n;
    for(int i = 1;i <= n;++i)
        for(j = 1;j <= i;++j)
            cin>>D[i][j];
    cout<<MAXSum(1,1)<<endl;
    return 0;
}