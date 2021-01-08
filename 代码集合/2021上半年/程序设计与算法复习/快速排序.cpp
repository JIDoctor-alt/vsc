#include<iostream>
#include<algorithm>
using namespace std;
int a[10005];
int partition(int l,int r)
{
    int pivot = a[r];
    int i = l - 1;
    for(int j = l;j < r;++j)
    {
        if(a[j] < pivot)
        {
            ++i;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1],a[r]);
    return i + 1;
}
void QuickSort(int p,int s)
{
    if(p >= s)
        return;
    //每次将比a[s]小的数放到它的左边，比a[s]大的数放到它的右边
    int q = partition(p,s);
    QuickSort(p,q - 1);
    QuickSort(q + 1 , s);
}
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>a[i];
    QuickSort(0,N - 1);
    for(int i = 0;i < N;++i)
        cout<<a[i]<<" ";
    return 0;
}