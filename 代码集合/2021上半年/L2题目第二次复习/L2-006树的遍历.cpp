#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
vector<int> post;//后序遍历
vector<int> order;
map<int,int> level;
//只需要知道中序遍历的开始，结束下标即可
void getpost(int root,int start,int end,int index)
{
    if(start > end)
        return;
    int i = start;
    //从中序中找到根结点的位置
    while(i < end && order[i] != post[root])
        ++i;
    level[index] = post[root];//
   // cout<<index<<": "<<post[root]<<endl;
    getpost(root - (end - i) - 1,start,i - 1,2 * index );
    getpost(root - 1, i + 1,end,2 * index + 1);
}
int main()
{
    int N;
    cin>>N;
    post.resize(N);
    order.resize(N);
    
    for(int i = 0;i < N;++i)
    {
        cin>>post[i];//后
    }
    for(int i = 0;i < N;++i)
    {
        cin>>order[i];
    }
    getpost(N - 1,0,N-1,1);

    int ans = 0;
    auto it = level.begin();
    cout<<it->second;
    while(++it != level.end())
        cout<<" "<<it->second;
    return 0;
}