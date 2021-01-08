#include<iostream>

using namespace std;
int num;
int tree[1<<20];//1左移20位
//二叉树 有 2的k次方 
void BST(int a){
    if(tree[a] == 0)
        tree[a] = num;
    else if(tree[a] < num)//如果小于
        BST(a<<1);//左子树
    else 
        BST(a<<1|1);//右子树
}
int main(){
    int n;
    cin>>n;
    //建立二叉搜索树
    for(int i = 0;i < n;i++){
         cin>>num;
         BST(1);
    }
    bool flag = true;
    //一共有n个结点  cnt记录输出的结点数目，如果存在中途有空结点说明不是完全二叉树
    for(int  cnt  = 1,k = 1;cnt <= n;k++){
        if(tree[k] == 0)
            flag = false;
        else {
            cout<<tree[k];
            if(cnt++ != n)cout<<" ";
        }
    }
    if(flag )cout<<"\nYES";
    else cout<<"\nNO";
       

    return 0;
}