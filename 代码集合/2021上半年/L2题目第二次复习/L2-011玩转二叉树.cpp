#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int MAX_V = 31;
int N;
int pre[MAX_V];
int order[MAX_V];
map<int,int> level;
void getpost(int root ,int s,int e,int index)
{
   if(s > e)
        return;
   level[index] = pre[root];//前序遍历
   int i = s;
   while(i <= e && pre[root] != order[i])//在中序找那个找到根结点
        ++i; 
    //区分左子树和右子树
    getpost(root + 1 + i - s,i + 1,e,2 * index);
    getpost(root + 1,s,i - 1,2 * index + 1);

}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>order[i];
    for(int i = 0;i < N;++i)
        cin>>pre[i];
    getpost(0,0,N-1,1);
    int ans = 0;
    for(auto w : level)
    {
        ++ans;
        if(ans != 1)
            cout<<" ";
        int num = w.second;
        cout<<num;
    }
    return 0;
}