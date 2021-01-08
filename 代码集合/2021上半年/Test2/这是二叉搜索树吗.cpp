#include<iostream>
#include<vector>

using namespace std;
bool isMirror;
vector<int> pre,post;
void getpost(int root,int tail){
    //得到后序遍历的结果
    if(root > tail)return ;//如果根结点大于尾部结点，
    //i为左子树的根结点  j为
    int  i = root + 1,j = tail;

    //是二叉搜索树
    if(!isMirror){
        //比root小的在左边
        while(i <= tail && pre[i] < pre[root]) i++;
        //当发现一个 pre[i]大于pre[root]   比根结点大的有多少
        while(j > root &&  pre[root] <= pre[j])j--;
    }else{
        //如果是镜像  比根结点大的
        while(i <= tail && pre[root] <= pre[i])i++;
        //比根结点小的
        while(j > root && pre[root] > pre[j])j--;
    }
    if(i - j != 1)return;
    //左子树的第一个结点
    getpost(root+1,j);
    //右子树的第一个结点
    getpost(i,tail);
    post.push_back(pre[root]);
}

int main(){
    int n;
    cin>>n;
    pre.resize(n);
    //前序遍历的结果
    for(int i = 0;i < n;i++)
        cin>>pre[i];
        //二叉树的左边，右边
    getpost(0,n-1);
    if(post.size()!=n){
        isMirror = true;
        //是镜像
        post.clear();
        getpost(0,n-1);
    }
    if(post.size() == n){
        cout<<"YES"<<endl;
        cout<<post[0];//根结点
            for(int i = 1;i < n;i++)
                cout<<" "<<post[i];
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}