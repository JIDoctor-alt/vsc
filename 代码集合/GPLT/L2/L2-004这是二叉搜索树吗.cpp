#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
//可能只有左子树，也可能只有右子树
bool flag;
vector<int> pre;
int postorder[1005],cur;
void dfs(int st,int ed){
    if(st > ed)
        return;
    int root = pre[st];

    int i = st + 1,j = ed;
    if(flag){
        //左子树小于根结点
        while(pre[i] < root && i <= j)
            ++i;
        //右子树大于等于根结点 
        while(pre[j] >= root && i <= j)
            --j;
    }else{
        while(pre[i] >= root && i <= j)
            ++i;
        while(pre[j] < root && i <= j)
            --j;
    }

    if(i - j != 1)
        return;

    dfs(st + 1,i - 1);
    dfs(i,ed);
    postorder[cur++] = root;
    
}
int main()
{
    cin>>N;
    pre.resize(N);
    for(int i = 0;i < N;++i){
        cin>>pre[i];
    }
    flag = true;
    cur = 0;
    dfs(0,N-1);
    if(cur != N){
        flag = false;
        cur = 0;
        dfs(0,N-1);
    }

    if(cur == N){
        cout<<"YES"<<endl;
        cout<<postorder[0];
        for(int i = 1;i < N;++i)
            cout<<" "<<postorder[i];
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}