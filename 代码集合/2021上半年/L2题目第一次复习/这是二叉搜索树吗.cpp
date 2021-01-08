#include<iostream>

using namespace std;
int n,pre[1005],post[1005],cnt  = 0;
bool flag ;

void build(int l,int r){
    if(l > r)return;
    int i = l + 1,j = r;
    if(!flag){
        //二叉搜索树的左子树中所有结点的键值都小于根结点的键值
        while(i < r && pre[i] < pre[l])++i;
        //右子树中所有结点的键值大于等于该结点的键值
        while(j > l && pre[j] >= pre[l])--j;
    }else{
        //是镜像的化刚好相反
        while(i < r && pre[i] >= pre[l])++i;
        while(j > l && pre[j] < pre[l])--j;
    }
    if(i-j != 1)return ;
    //左子树的最后一个结点j
    build(l+1,i-1);
    //右子树
    build(i,r);
    //后续遍历的结果
    post[cnt++] = pre[l];
}

int main(){
    cin>>n;
    //将前序遍历的输入存入数组
    for(int i = 0;i < n;i++)cin>>pre[i];
    build(0,n-1);
    if(cnt != n){
        flag = true;
        cnt = 0;
        build(0,n-1);
    }
    if(cnt != n)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<post[0];
        for(int i = 1;i < cnt;i++)
            cout<<" "<<post[i];
        cout<<endl;
    }
    return 0;
}