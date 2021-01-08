#include<iostream>
#include<iomanip>
#define EPS 0
using namespace std;
int N,K;
int H[100100],W[100100];
bool Valid(int c)
{
    int cnt = 0;
    for(int i = 0;i < N;++i)
        cnt += (H[i]/c)*(W[i]/c);
    return cnt >= K;//如果分得的蛋糕大于或者等于K边长还可以再扩大
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>K;
    for(int i = 0;i < N;++i)
        cin>>H[i]>>W[i];
    int L = 1,R = 1<<30;
   // int lastPos;
    while(R - L > EPS)
    {
        int mid =(L + R + 1)/2;
       // int mid = (R + L)/2;
        if(Valid(mid)){
       //     lastPos = mid;
            L  = mid ;
        }
        else 
        //    R = mid - 1;
            R = mid - 1;
    }
   // cout<<lastPos<<endl;
    cout<<L<<endl;
    return 0;
}
// 大于等于X最左边的位置
//mid右边的都是答案，找答案中最靠左边的
while(L < R)
{
    mid = (L+R)/2;//向下取整
    if(arr[mid] >= x)  //check(mid)
        R = mid; //mid是一个答案并且答案可能比mid更小（在mid左边）           
    else 
        L = mid + 1; //这里的mid一定不是答案 L < R （太靠左边了）去右边找
}
//小于等于X的最右边的位置
while (L < R)
{//注意有一个上下界的问题  L  = 3, R = 4时 死循环
    //mid = (L+R)/2;
  //所以改成上取整  这时候L为4 ； 4 < 4就结束了
    mid = (L+R+1)/2;
    if(arr[mid] <= x)
        L = mid;
    else 
        R = mid - 1;
}
cout<<L或者R<<endl; //L和R都是结果答案
