#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int order[10005],pre[10005];
int level[10005];
int N;
void sovle(int root,int r,int l,int index)
{
    if(l < r)
        return;
    int x  = pre[root];

    int i = r;

    while(i <= l && x != order[i])
        ++i;

    level[index] = x;
    sovle(root + 1,r,i - 1,2 * index + 2);
    sovle(root + (i - r) + 1 ,i + 1,l,2 * index + 1);
}
int main()
{
    cin>>N;
    memset(level,-1,sizeof(level));
    for(int i = 0;i < N;++i)
    {
        cin>>order[i];
    }
    for(int i = 0;i < N;++i)
    {
        cin>>pre[i];
    }
    sovle(0,0,N-1,0);
     int cnt = 0;
     for(int i = 0;i < 10005 && cnt <= N;++i)
     {
         if(level[i] != -1)
         {
             ++cnt;
             if(cnt != 1)
                cout<<" ";
             cout<<level[i];
         }
     }
    return 0;
}