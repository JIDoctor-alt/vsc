#include<iostream>
using namespace std;
struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
bool isBalanced(TreeNode* root) {

    if(root == NULL)
        return true;

    int lef = deepTree(root->left,0);
    int rig = deepTree(root->right,0);
    
    if(abs(lef - rig) > 1)
        return false;
    return isBalanced(root->left)&&isBalanced(root->right);

}
int deepTree(TreeNode *tree,int deep)
{
    if(tree == NULL)
        return deep;
    int leftdepp = deepTree(tree->left,deep+1);
    int rightdeep = deepTree(tree->right,deep+1);

    return max(leftdepp,rightdeep);
}
int main()
{
    return 0;
}