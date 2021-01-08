#include<iostream>
#include<algorithm>
using namespace std;
int N,C;
int a[100100];
bool Valid(int c)
{
    int cnt = 1,totalCount = a[0];
    for(int i = 1;i < N;++i)
    { //两畜栏之间的距离是否超过了给定的距离（超过既可以再分配一个牛
       if(a[i] - totalCount >= c)
        {
            totalCount = a[i];
            ++cnt;
        }
        else //如果两畜栏的距离小于等于给定的距离则不能放牛
            continue;
    }
    return cnt >= C;//如果合适则查看有没有更大的距离
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>C;
    for(int i = 0;i < N;++i)
        cin>>a[i];
    sort(a,a+N);//注意对牛的畜栏编号排序
    int L = 0,R = 1<<30;
    while (L < R)
    {
        int mid = (L+R+1)/2;
        if(Valid(mid))
            L = mid ;//尽可能的大（靠右）
        else 
            R = mid - 1;
    }
    cout<<L<<endl;
    return 0;
}