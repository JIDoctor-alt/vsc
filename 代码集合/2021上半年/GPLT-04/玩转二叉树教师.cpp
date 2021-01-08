#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int val,L,R;
};
vector<node> t;
vector<int> preOrder, inOrder;
map<int,int> inPos;
int p = -1;
///中序   先序
int buildTree(int inL,int inR,int preL,int preR)
{
    if(inL > inR || preL > preR)
        return -1;
    //根结点    
    int rt = preOrder[preL];
    //得到中序遍历的下标
    int rtInPos = inPos[rt];

    //
    int rtPos = ++p;
    //将二叉树存起来
    t[rtInPos].val = rt;
    //中序遍历 左端点， 右端点   先序遍历的做区间 左端点 右端点（）
    t[rtPos].R = buildTree(inL,rtInPos - 1,preL + 1,rtInPos  - inL + preL);
    //右区间  中序的左端点 右端点   先序的左端点，右端点
    t[rtPos].L = buildTree(rtInPos + 1,inR,preR + 1 - inR + rtInPos,preR);
    //返回元素下标
    return rtPos;
}
//层次遍历二叉树
void levelTraversal()
{
    vector<int> ans;
    queue<node> q;
    //根节点入队列
    q.push(t[0]);
    while (!q.empty())
    {
        //出队
        auto rt = q.front();
        q.pop();
        //加入数组
        ans.push_back(rt.val);
        //左子树不空，左节点入队
        if(rt.L != -1)
            q.push(t[rt.L]);
            //右子树不空，右结点入队
        if(rt.R != -1)
            q.push(t[rt.R]);
    }
    //输出结果
    for(int i = 0;i < ans.size();++i)
            cout<<ans[i]<<(i <  ans.size() - 1 ? " ":"\n");
}
int main()
{
    int N;
    cin>>N;
    preOrder.resize(N);
    inOrder.resize(N);
    t.resize(N);
    for(int i = 0;i < N;++i)
    {
        cin>>inOrder[i];
        //存储中序遍历元素的下标
        inPos[inOrder[i]] = i;
    }
    for(int i = 0;i < N;++i)
        cin>>preOrder[i];
        //中序的左右端点， 先序的左右端点
    int root = buildTree(0,N-1,0,N-1);
    levelTraversal();
    return 0;
}