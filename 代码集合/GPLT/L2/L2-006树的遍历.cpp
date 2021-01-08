#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> post,order;
int level[10005];
int N;
//根据中序遍历的分而治之实现层次遍历，根据后续遍历数组找到根结点。
//注意下标，左子树或者右子树的长度，以及根结点的位置
void sovle(int root ,int s,int e,int index){
    if(s > e)
        return;
    int x = post[root];
    int i = s,j = e;
    while(i <= j && order[i] != x)
        ++i;
    level[index] = x;
    //左子树  根结点减去右子树的长度(此时得到的是右子树数字最左边的数)
    sovle(root - (e- i) - 1,s,i-1,2*index + 1);
    sovle(root - 1,i + 1,e,2*index + 2);//右子树的长度
}
int main()
{
    cin>>N;
    post.resize(N);
    order.resize(N);
    memset(level,-1,sizeof(level));
    for(int i = 0;i < N;++i)    
        cin>>post[i];
    for(int i = 0;i < N;++i)
        cin>>order[i];
    sovle(N-1,0,N-1,0);
    int ans = 1;
    cout<<level[0];
    for(int i = 1;i < 10005 && ans != N;++i){
         if(level[i] != -1){
        cout<<" "<<level[i];
                 ++ans;
         }
        
    }

    return 0;
}