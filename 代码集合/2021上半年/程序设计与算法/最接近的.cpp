#include<iostream>
#include<iomanip>
#define EPS 1e-6
using namespace std;
long long a[100100],b[100100];
int LowerBound(int p,int n)
{
    int L = 0;
    int R = n - 1;
    if(a[L] > p)//如果给定的值比其中的任何值都小
        return a[L];
    if(a[R] < p)//如果给定的值比其中的任何值都大
        return a[R];
    while(L <= R)
    {
        int mid = L + (R - L)/2;
        if(p == a[mid])//有相等的元素
            return a[mid];
        else if(p > a[mid])
            L = mid + 1;
        else 
            R = mid - 1;
    }
    //没有相等的元素查找最接近的
    int x = abs(a[L] - p);
    int y = abs(a[R] - p);
    if(x < y)//查找距离近的
        return a[L];
    else if(x > y)//y小输出a[R]
        return a[R];
    else //如果距离相同输出小的
        return (a[L] < a[R] ? a[L] : a[R]);
    return 0;
}
int main()
{
    int n,m;
    cin>>n;
    for(int i = 0;i < n;++i)
        cin>>a[i];
    cin>>m;
    for(int i = 0;i< m;++i)
        cin>>b[i];
    for(int i = 0;i < m;++i)
        cout<<LowerBound(b[i],n)<<endl;
    return 0;
}