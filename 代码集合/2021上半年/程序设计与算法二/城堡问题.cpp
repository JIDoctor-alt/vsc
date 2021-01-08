#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int room[51][51];
int color[51][51];
int m,n,maxArea,roomNum,roomArea;
void DFS(int i,int j)
{
    if(color[i][j])
        return;
    color[i][j] = roomNum;
    roomArea++;
    if((room[i][j] & 1 )== 0)DFS(i,j-1);
    if((room[i][j] & 2 )== 0)DFS(i-1,j);
    if((room[i][j] & 4 )== 0)DFS(i,j+1);
    if((room[i][j] & 8 )== 0)DFS(i+1,j);
}
int main()
{
    cin>>m>>n;
    for(int i = 1;i <= m;++i)
        for(int j = 1;j <= n;++j)
            cin>>room[i][j];
    memset(color,0,sizeof(color));
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
        { 
            if(!color[i][j])
            {
               ++roomNum;roomArea = 0;
               DFS(i,j);
               maxArea = max(maxArea,roomArea);
            }
        }
    }
    cout<<roomNum<<endl;
    cout<<maxArea<<endl;   
    return 0;
}