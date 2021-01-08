#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
vector<set<int>> st;
//注意计算Nt两个集合都有的不相等的整数的个数 和 减去相同的即可不会超时
int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    st.resize(N+1);
    for(int i = 1;i <= N;++i){
        cin>>M;
        while(M--){
            int id;
            cin>>id;
            st[i].insert(id);
        }
    }
    cin>>K;
    while(K--){

        int x,y;
        cin>>x>>y;
        int ans = 0;
        for(auto w : st[x]){
            if(st[y].count(w) != 0){
                ++ans;
            }
        }
        int nt = st[x].size() + st[y].size() - ans;
        cout<<fixed<<setprecision(2)<<(ans/(nt*1.0))*100<<"%"<<endl;
    }
    return 0;
}