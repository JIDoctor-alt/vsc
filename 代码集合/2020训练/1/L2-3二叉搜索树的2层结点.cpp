#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node *Position;
typedef Position BiTree;
typedef int  ElementType;
struct node
{
    ElementType data;
    BiTree left;
    BiTree right;
};
int N,maxdeep = -1;
vector<vector<int> > NUM(1005);
void insertNode(BiTree& t,int x,int deep)
{
    if(t == nullptr)
    {
        BiTree newNode = (BiTree)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->left = nullptr;
        newNode->right = nullptr;

        t = newNode;

        NUM[deep].push_back(x);

        if(maxdeep < deep)
            maxdeep = deep;
        return;
    }

    if(t->data >= x)
    {
        insertNode(t->left,x,deep + 1);
    }
    else 
    {
        insertNode(t->right,x,deep + 1);
    }

}
int main()
{
    BiTree tree = nullptr;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int x;
        cin>>x;
        insertNode(tree,x,1);
    }
    int cnt = NUM[maxdeep].size() + NUM[maxdeep -1].size();
    cout<<cnt<<endl;
    return 0;
}