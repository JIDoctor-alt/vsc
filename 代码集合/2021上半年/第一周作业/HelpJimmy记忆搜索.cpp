#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x1,x2,h;
} plat[1010];
bool cmp(point a,point b)
{
    return a.h>b.h;
}
int N,X,Y,MAX;
int  num[1010][2];

//从上到下记忆搜索（人人为我）第i个平台 a向左或者向右 ,x坐标从该点下落
int dfs(int i,int a,int x)
{
    //如果从这一点下跳 有结果（已经是最小的了）就直接返回
    if(num[i][a]!=-1)    return num[i][a];

    //左右不能跳就设置为最大值
    int left=100000000,right=100000000;


    bool flag=true;  ///可以往下跳
    for(int j=i+1; j<=N; j++)
    {

        //大于高度就跳死了！！！ 这里只要判断下高度就不要往下判断了（因为是按照高度从大到小排列的
        //从上到下第i层不能向下跳 的话，那么第i+1层就更不能了
        if(plat[i].h-plat[j].h>MAX)
        {
            flag=false;
            break;
        }

        //可以跳到下一个板子  在平台左右范围内
        if(x>=plat[j].x1&&x<=plat[j].x2)
        {

            left=dfs(j,0,plat[j].x1)+plat[i].h-plat[j].h+x-plat[j].x1;
            right=dfs(j,1,plat[j].x2)+plat[i].h-plat[j].h+plat[j].x2-x;

            ///已经找到了
            flag=false;
            break;
        }
    }
    //找左右最小的
    num[i][a]=min(left,right);
    //如果下面没有平台且高度在允许范围内（直接返回这个平台的高度 能直接跳下来
    //这里只能直接跳下来
    if(flag&&plat[i].h<=MAX)
        num[i][a]=plat[i].h;
    return num[i][a];


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(num,-1,sizeof num);
        scanf("%d%d%d%d",&N,&X,&Y,&MAX);


        plat[0].x1=X, plat[0].x2=X, plat[0].h=Y;///将终点作为一个平台
        for(int i=1; i<=N; i++)
            scanf("%d%d%d",&plat[i].x1,&plat[i].x2,&plat[i].h);
        sort(plat,plat+N+1,cmp);
        printf("%d\n",dfs(0,1,X));
    }
    return 0;
}