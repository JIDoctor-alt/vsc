#include<iostream>
#include<string>

using namespace std;
int sovle(string p,string o,int n){//左子树，右子树，节点个数
    int i;
    if(n == 0)return 0;
    //先找到中序遍历中 根结点的下标
    for(i = 0;i < n;i++){
        if(p[0] == o[i])break;//
    }
    string s = p.substr(1);//左子树的根
    string s1 = p.substr(i+1);//右子树的根
    //e为中序遍历的右子树
    string e = o.substr(i+1);
    //先序数组中，左子树的根结点s，  中序遍历中，最左边的为左子树，，根  ，右子树
    int x = sovle(s,o,i)+1;//左子树深度
    int y = sovle(s1,e,n-i-1)+1;//右子树深度  (右子树的节点数为  减去左子树节点数i
    //根结点 1)
    return x > y ? x : y;
}
int  main(){
    int N;
    cin>>N;
    string Pre,Order;
    getchar();
    getline(cin,Pre);
    getline(cin,Order);
    int  ans = sovle(Pre,Order,N);
    cout<<ans<<endl;
    return 0;
}