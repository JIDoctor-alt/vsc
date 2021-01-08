#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//后序 和 中序
int postorder[10005],inorder[10005];
int level[10005];
int N;
void solve(int root,int s,int e,int index)
{
    if(s > e)//等于不行（等于的时候也要分配
        return;


    int x = postorder[root];

    level[index] = x;
    //cout<<"level------------------"<<level[index]<<endl;

    int i = s;
    //0-1 1-2 2-3 3-4

    while(i < e && inorder[i] != x)
        ++i;

    int l = i - s;
   // cout<<"i-----------"<<i<<"-----x--"<<inorder[i]<<endl;
    //cout<<"left-------"<<postorder[root - l - 1]<<"right--------------"<<postorder[root - 1]<<endl;    
    //e - i 才是右子树的长度
    solve(root - (e - i) - 1, s , i-1 , 2*index + 1);//左边
    //i- s为左子树的长度
    //cout<<"=================\n";
    solve(root - 1,i+1 , e , 2*index + 2);//右边

}
int main()
{
    memset(level,-1,sizeof(level));
    
    cin>>N;

    for(int i = 0;i < N;++i)
        cin>>postorder[i];
    
    for(int i = 0;i < N;++i)
        cin>>inorder[i];
    
   
    solve(N-1,0,N-1,0);
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
    return 0;
}