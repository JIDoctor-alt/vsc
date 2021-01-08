#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre;
vector<int> post;
bool isMirror;
void getpost(int root,int tail)
{
    if(root > tail)
        return;
    int i = root + 1, j = tail;
    if(!isMirror)//二叉搜索树
    {
        while(i <= tail && pre[root] > pre[i])
            ++i;
        while(j > root && pre[root] <= pre[j])
            --j;
    }
    else 
    {
        while(i <= tail && pre[root] <= pre[i])
            ++i;
        while(j > root && pre[root] > pre[j])
            --j;
    }
    if(i - j != 1)
        return;
    getpost(root + 1,j);//左边
    getpost(i,tail);//右边
    post.push_back(pre[root]);
}
int main()
{
    int n;
    cin>>n;
    pre.resize(n);
    for(int i = 0;i < n;++i)
        cin>>pre[i];
    getpost(0,n-1);
    if(post.size() != n)
    {
        isMirror = true;//镜像
        post.clear();
        getpost(0,n-1);
    }
    if(post.size() == n)
    {
        cout<<"YES"<<endl;
        cout<<post[0];
        for(int i = 1;i < post.size();++i)
        {
            cout<<" "<<post[i];
        }
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}