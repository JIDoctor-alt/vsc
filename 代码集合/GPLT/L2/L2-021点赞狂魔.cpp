#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
/*标签出现的平均次数，结构体内函数的定义*/
struct node{
    string name;
    int x;
    double av;
    node(string n,int a,double b):name(n),x(a),av(b){}
};
vector<node> ans;
bool cmp(node &e1,node &e2)
{
    if(e1.x != e2.x)
    {
        return e1.x > e2.x;
    }
    else
    {
        return e1.av < e2.av;
    }
    
}
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        set<int> st;
        int m;
        string name;
        cin>>name;
        cin>>m;
        for(int j = 0;j < m;++j)
        {
            int x;
            cin>>x;
            st.insert(x);
        }
        double av =  (1.0*m) / st.size();
        int cnt = st.size();
        ans.push_back({name,cnt,av});
    }
    sort(ans.begin(),ans.end(),cmp);
    ans.push_back({"-",0,0});
    ans.push_back({"-",0,0});
    cout<<ans[0].name<<" "<<ans[1].name<<" "<<ans[2].name;
    return 0;

}