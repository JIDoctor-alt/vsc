#include<iostream>
#include<vector>
/*与后序中序转换为前序的代码相仿*
 无需构造二叉树再进行广度搜索，只不过加一个变量index，表示当前的根结点
 在二叉树中所对应的下标  从0开始，所以进行一次输出先序的递归的时候，就可以
 把根结点下标所对应存储在level数组中（一开始把level都置为-1表示此处没有
 结点，这样在递归完成后level数组中非-1的数就是按照下标排列的层次序列输出
*/
using namespace std;
vector<int> post,in,level(100000,-1);
void pre(int root,int start,int end,int index){
    if(start > end)return ;
    int i = start;
    while(i < end && in[i] != post[root])i++;//找到根结点的位置
    level[index] = post[root];//index为下一个数的下标
    pre(root-1-end+i,start,i-1,2*index + 1);//左子树
    pre(root-1,i+1,end,2*index+2);//右子树
}
int main(){
    int n,cnt = 0;
    cin>>n;
    post.resize(n);
    in.resize(n);
    for(int i = 0;i < n;i++)cin>>post[i];
    for(int i = 0;i < n;i++)cin>>in[i];
    pre(n-1,0,n-1,0);//后续遍历从最后一个结点开始为根结点
    for(int i = 0;i < level.size();i++){
        if(level[i] != -1 && cnt != n-1){
            cout<<level[i]<<" ";
            cnt++;
        }else if(level[i] != -1){
            //最后一个结点
            cout<<level[i];
            break;
        }
    }
    return 0;
}