#include<iostream>
using namespace std;
int N,a[100010],t[100010];
//注意long long
long long ans = 0;
void msort(int L,int R)
{
    if(L >= R)return ;

    int mid = (L+R)/2;

    msort(L,mid);
    msort(mid+1,R);

    int i = L,j = mid+1,k = 0;
    while(i <= mid && j <= R)
    {
        if(a[i] <= a[j])
            t[k++] = a[i++];
        else {
            t[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid)
        t[k++]  = a[i++];
    while(j <= R)
        t[k++] = a[j++];
    for(int i = L,k = 0;i <= R;i++,k++)
        a[i] = t[k];
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;i++)
        cin>>a[i];
    msort(0,N-1);
    cout<<ans<<endl;
    return 0;
}