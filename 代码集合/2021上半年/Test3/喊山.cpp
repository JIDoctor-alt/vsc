#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> v(10010);
int book[10010];
int main(){
    int n,m,k,a,b;
    //n个山，m，k个方案
    cin>>n>>m>>k;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0;i < k;i++){
        cin>>a;
        queue<int> q;
        fill(book,book+10010,0);
        q.push(a);
        int level[10010];
        ///下标和最深
        int ans = 10010,maxlevel = 0;
        book[a] = 1;//表示已经访问
        while(!q.empty()){
            int top = q.front();
            q.pop();
            //找最大的深度
            if(level[top]  > maxlevel){
                //最远的山头
                maxlevel = level[top];
                ans  = 10010;
            }
            //记录编号最小的山头
            if(top != a)
                ans   = min(ans ,top);
                //广度遍历 每个邻接点
            for(int j = 0;j < v[top].size();j++){
                if(book[v[top][j]] == 0){
                    q.push(v[top][j]);
                    book[v[top][j]] = 1;
                    level[v[top][j]] = level[top] + 1;
                }
            }
        }
        if(ans != 10010)cout<<ans<<endl;
        else
        {
            cout<<0<<endl;
        }
        
     }
    return 0;
}