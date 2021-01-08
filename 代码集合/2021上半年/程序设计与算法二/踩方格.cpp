#include<iostream>
#include<cstring>
using namespace std;
int visited[100][100];
int DFS(int i,int j,int n)
{
    if(n == 0)
        return 1;
    visited[i][j] = 1;
    int num  = 0;
        //西
    if(!visited[i][j-1])num+= DFS(i,j-1,n-1);
    //东
    if(!visited[i][j+1])num+= DFS(i,j+1,n-1);
    //北 i+1 或者是 i-1无所谓 重要的是防止下标越界
    if(!visited[i+1][j])num+= DFS(i+1,j,n-1);
    //如果不从这个方格走（恢复初值）恢复现场信息
    visited[i][j] = 0;
    return num;
}
int main()
{
    memset(visited,0,sizeof(visited));
    int N;
    cin>>N;
    cout<<DFS(0,25,N)<<endl;
}