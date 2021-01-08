#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int order[100],post[100];
int level[1005];
int N;
void sovle(int root ,int s,int e,int index){
    if(s > e)
        return;

    int x = post[root];

    int i = s;

    while(i <= e && order[i] != x)
        ++i;

    level[index] = x;

    sovle(root + 1,s,i - 1,2*index + 2);

    sovle(root + (i - s) + 1,i + 1,e,2*index + 1);

}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>order[i];
    for(int j = 0;j < N;++j)
        cin>>post[j];
    memset(level,-1,sizeof(level));
    sovle(0,0,N-1,0);
    cout<<level[0];
    int ans = 1;
    for(int i = 1;i < 1005 && ans != N;++i){
        if(level[i] != -1)
        {
            cout<<" "<<level[i];
            ++ans;
        }
    }
    return 0;
}