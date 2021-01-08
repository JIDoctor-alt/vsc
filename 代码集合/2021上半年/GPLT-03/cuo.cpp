#include<iostream>
#include<iomanip>

using namespace std;
int a[100005],n[100005],p[100005],v[100005];
int main()
{
    int hptr,N;
    cin>>hptr>>N;
    for(int i = 0;i < N;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        n[x] = z;
        v[x] = y;
    }
    int eptr = hptr;
    for(int j = n[hptr];~j; j = n[j],eptr = n[eptr])
        p[j] = eptr;
    p[hptr] = -1;
    int iptr = hptr,jptr = eptr;
    while(iptr != jptr)
    {
        if(iptr!= jptr){
            a[jptr] = iptr;
            jptr = p[jptr];
        }
        if(iptr != jptr)
        {
            a[iptr] = jptr;
            iptr = n[iptr];
        }
    }
    a[iptr] = -1;
    for(int i = eptr; ~i ;i = a[i])
    {
        cout<<setw(5)<<setfill('0')<<i<<" ";
        cout<<v[i]<<" ";
        if(~a[i])
             cout<<setw(5)<<setfill('0')<<a[i]<<endl;            
        else 
             cout<<"-1"<<endl;
    }
    return 0;
}