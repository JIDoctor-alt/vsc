#include<iostream>
#include<vector>
using namespace std;
vector<int> in,pre,level(100000,-1);

//注意反转后的二叉树 分而治之 i/2  i i+1  2I 2I+1 
void MegerSort(int root,int s,int e,int index){

     if(s > e)return;
     int i = s;
     //找到中序遍历中的根结点
     while(i < e && in[i] != pre[root])i++;
     //下标
     //层次遍历后的数组（反转后的
     level[index] = pre[root];
     //反转后的直接将下标更改即可
     MegerSort(root+1,s,i - 1,2*index + 2);
     MegerSort(root+1+i-s,i + 1,e,2*index + 1);
}
int main(){
    int N;
    cin>>N;
    in.resize(N);
    pre.resize(N);
    for(int i = 0;i < N;i++)
        cin>>in[i];
    for(int i = 0;i < N;i++)
        cin>>pre[i];
    int ans = 0;
    MegerSort(0,0,N-1,0);
    for(int i = 0;i < level.size();i++){
        if(level[i] != -1 &&  ans != N-1){
            cout<<level[i]<<" ";
            ans++;
        }else if(level[i] != -1){
            cout<<level[i];
            break;//最后一个结点
        }
    }


    return 0;
}