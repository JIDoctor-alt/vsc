#include<iostream>
#include<vector>

using namespace std;
vector<int> in,pre,level(100000,-1);
//分而治之  （start为中序遍历的左（右）子树起点 end为左（右）的终点
void post(int root,int start,int end,int index){
    if(start > end)return ;
    int i = start;
    //找到中序遍历的根结点
    while(i < end && in[i] != pre[root])i++;
    level[index] = pre[root];//层次遍历根结点的位置存放在数组中
    //左子树 的 根结点 已经起点 终点，下一个结点所存放的下标
    post(root+1,start,i-1,2*index + 2);
    //右子树 的 根结点（根的下标+左子树的长度 + 1 就是右子树的第一个结点）
    //起始下标（i加1）
    post(root + 1 + (i - start),i+1,end,index*2+1);//左右交换
}
int main(){
    int n,cnt = 0;
    cin>>n;
    in.resize(n);
    pre.resize(n);
    for(int i = 0;i < n;i++)cin>>in[i];
    for(int i = 0;i < n;i++)cin>>pre[i];
    post(0,0,n-1,0);//0先序遍历的根结点  0中序遍历的第一个结点 n-1中序遍历的最后一个结点 0从下标为0存放
    for(int i = 0;i < level.size();i++){
        if(level[i]!=-1 && cnt != n-1){
            //不是空节点，且没有输出全部结点
            cout<<level[i]<<" ";
            cnt++;//计数
        }else if(level[i] != -1){
            //输出最后一个结点时
            cout<<level[i]<<endl;
            break;//跳出循环
        }
    }
    return 0;
}