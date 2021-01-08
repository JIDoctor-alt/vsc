#include<iostream>
#include<cmath>
using namespace std;
int N,M;
int minArea = 1 << 30;//最优表面积
int area ; //正在搭建中的蛋糕的表面积
int minV[22] = {0},minS[22] = {0};
//剩下的半径最大
int maxVJudge(int r,int h,int n)
{
    int maxV = 0;
    for(int i = 0;i < n;++i)//每一层比下一次半径小1（一共剩下n层）
        maxV += (r-i)*(r-i)*(r-i);
    return maxV;
}
//要用n层去凑体积V，最底层半径不能超过r，高度不能超过h
//求出最小表面积放入minArea  
void DFS(int v,int r,int h,int n)
{//v剩余的体积，剩余的半径(最大），剩余的高度（最高），剩余的层数（还有几层要搭建）
    if(n == 0)
    {
        if(v){
            return;
        }
        else 
        {
            minArea = min(minArea,area);
            return;
        }
    }
    //剪枝2体积无法安排
    if(v <= 0)
        return;
    ///剪枝3
    if(minV[n] > v)return;
    //剪枝4
    if(maxVJudge(r,h,n) < v)return;
     //剪枝1
    if(minS[n] + area >= minArea)
        return;
    //枚举半径和高度（范围为r到n h 到n)
    ///因为剩下每一层半径至少都为1
    for(int rr = r;rr >= n;--rr)
    {
        if(n == M)//底面积
            area = rr * rr;
        for(int  hh = h;hh >= n;--hh)
        {
            area += 2 * rr * hh;
            //剩下要分配的面积减小，半径减小，高度减小，要分配的层数减小
            DFS(v - rr*rr*hh,rr-1,hh-1,n-1);
            //恢复现场信息
            area -= 2 * rr * hh;
        }
    }
}
int main()
{
    
    cin>>N>>M;
    //求出上i层的最小面积，最小体积
    for(int i = 1;i <= M;++i)
    {
        minV[i] = minV[i-1] + (i*i*i);
        minS[i] = minS[i-1] + (2*i*i);
    }
    //最底层的最大半径，最大高度（总高度 -上M-1层的最小高度，总体积 -上M-1层最小半径）
    int maxR = sqrt((N-minV[M-1])/M) + 1;
    int maxH = (N-minV[M-1])/(M*M) + 1;
    DFS(N,maxR,maxH,M);
    cout<<(minArea != 1 << 30 ? minArea : 0)<<endl;
    return 0;
}