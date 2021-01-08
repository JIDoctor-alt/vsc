#include<iostream>
using namespace std;
int n,typeNum;
int a[100100],t = 0;
void HeapPush(int u)
{
    a[++t] = u;
    for(int p = t,pa = p/2; p > 1 && a[p] < a[p/2];p = pa)
    {
        pa = p/2;
        swap(a[p],a[pa]);
    }
}
int HeadPop()
{
    int ans = a[1];
    swap(a[1],a[t--]);
    for(int p = 1,c = 2;2 * p <= t;p = c)
    {
        c = 2 * p;
        if(c < t && a[c + 1] < a[c])
            ++c;
        if(a[p] < a[c])
            break;
        swap(a[p],a[c]);
    }
    return ans;
}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>typeNum;
        if(typeNum == 1)
        {
            int u;
            cin>>u;
            HeapPush(u);
        }
        else 
        {
            cout<<HeadPop()<<endl;
        }
    }
    return 0 ;
}