#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> num,level;
int GetLeftLength(int n){

}
void solve(int ALeft,int ARight,int index){
    int n = ARight - ALeft +1;//有这些要计算的数

    if(n == 0)return ;
    int L ;
    L = GetLeftLength(num.size());//计算n个结点的二叉树 的左节点个数
    level[index] = num[ALeft + L];
    ///左节点存放的下标
    int TRootLeft = 2 * index + 1;
    ///有节点存放的下标
    int TRootRiht = 2 * index + 2;

    solve(ALeft,ALeft+L-1,TRootLeft);
    solve(ALeft+L+1,ARight,TRootRiht);
}
int main(){
    int number;
    while(cin>>number){
        num.push_back(number);
    }
    int n = num.size();
    solve(0,n-1,0);
    return 0;
}