#include<iostream>
#include<algorithm>
using namespace std;
int a[10005],K;
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
int QuickSort(int p,int s)
{
    //当只有一个数且正好是该数
    if(p >= s && p == K - 1)
        return p;
    //每次将比a[s]小的数放到它的左边，比a[s]大的数放到它的右边
    int m = partition(p,s);
    if(m == K - 1)
        return m;
    else if(m < K - 1)
        return QuickSort(m + 1, s);
    else if(m > K - 1)
        return QuickSort(p,m - 1);
 /*   QuickSort(p,q - 1);
    QuickSort(q + 1 , s);*/
}
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>a[i];

   /* for(int i = 0;i < N;++i)
        cout<<a[i]<<" ";*/
    cin>>K;
    int index = QuickSort(0,N - 1);
    //第K大的数
    cout<<"the "<<K<<" big of number: "<<a[index]<<endl;
    return 0;
}