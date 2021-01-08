#include<iostream>
#include<vector>
using namespace std;
void QuickSort(int a[],int s,int e)
{
    if(s >= e)
    {
        return;
    }

    int k = a[s];
    int i = s,j = e;
    while(i != j)
    {
        while(a[j] >= k && i < j)
        {
            --j;
        }
        swap(a[i],a[j]);
        while(a[i] <= k && i < j)
        {
            ++i;
        }
        swap(a[i],a[j]);
    }
    QuickSort(a,s,i - 1);
    QuickSort(a,i + 1, e);

}
int main()
{
    int a[10] = {1,3,23,323,42,32,55,42,25,67};
    QuickSort(a,0,9);
    for(int i = 0;i < 10;++i)
    {
        cout<<a[i]<<" "; 
    }
    return 0;
}