#include<iostream>
#include<vector>
using namespace std;

vector<int> pre;
vector<int> order;
vector<int> level = vector<int>(100000,-1);
int N;
void sovle(int root,int inL,int inR,int index)
{
    if(inL > inR)
        return;

    int i = inL;
    while(i < inR &&pre[root] != order[i])++i;
    level[index] = pre[root];

    sovle(root+1,inL,i - 1,2*index + 2);
    sovle(root + 1 + (i - inL),i+1,inR,2*index + 1);
}
int main()
{
    cin>>N;
    pre.resize(N);
    order.resize(N);
    for(int i = 0;i < N;++i)
        cin>>order[i];
    for(int i = 0;i < N;++i)
        cin>>pre[i];
    
    sovle(0,0,N-1,0);
    int ans = 0;
    for(int i = 0;i < level.size();++i)
    {
        if(level[i]!= -1 && ans != N-1){
            cout<<level[i]<<" ";
            ans++;
        }
        else if(level[i] != -1)
        {
            cout<<level[i];
            ///输出最后一个元素结束循环
            break;
        }
    }
    return 0;
}