#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int level[10005],order[10005],post[10005];
int N;
void jduge(int root,int s,int e,int index)
{
    if(s > e)
        return;

    int x = post[root];

    int i = s, j = e;
    while(i <= j && order[i] != x)
        ++i;
    
    level[index] = x;

    jduge(root + 1,s ,i - 1,2 * index + 2);
    jduge(root + 1 + (i - s),i + 1,e,2 * index + 1);

}
int main()
{
    memset(level,-1,sizeof(level));
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>order[i];
    for(int i = 0;i < N;++i)
        cin>>post[i];
    
    jduge(0,0,N-1,0);

    int cnt = 1;
    for(int i = 0;i < 10005 && cnt <= N;++i)
    {
        if(level[i] != -1)
        {
            if(cnt != 1)
                cout<<" ";
            cout<<level[i];
            ++cnt;
        }
    }
    cout<<endl;
    return 0;
}