#include<iostream>
using namespace std;
void Mege(int a[],int s,int  mid,int e)
{
    int pb = 0;
    int p1 = s,p2 = mid + 1;
    int temp[1001];
    while(p1 <= mid && p2 <= e)
    {
        if(a[p1] <= a[p2])
        {
            temp[pb++] = a[p1++];
        }
        else 
        {
            temp[pb++] = a[p2++];
        }
    }
    while(p1 <= mid)
    {
        temp[pb++] = a[p1++];
    }
    while(p2 <= e)
    {
        temp[pb++] = a[p2++];
    }
    for(int i = 0;i < pb;++i)
    {
        a[s+i] = temp[i];
        cout<<"==="<<endl;
    }

}
void MegerSort(int a[],int s,int e)
{
    if(s >= e)
        return;
    int mid = (s + e)/2;
    MegerSort(a,s,mid);
    MegerSort(a,mid + 1,e);
    Mege(a,s,mid,e);
}
int main()
{
    int a[10] = {1,3,23,323,42,32,55,42,25,67};
    MegerSort(a,0,9);
    for(int i = 0;i < 10;++i)
    {
        cout<<a[i]<<" "; 
    }
    return 0;
}