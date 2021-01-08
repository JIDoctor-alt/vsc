#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    int time;
};
bool cmp1(node &e1,node &e2)
{
    return e1.time < e2.time;
}
bool cmp2(node &e1,node &e2)
{
    return e1.time > e2.time;
}

vector<node> st;
vector<node> etime;
int n;
int main()
{
    cin>>n;
    while(n--)
    {
        string id;
        int a1,a2,a3;
        int b1,b2,b3;
        cin>>id;
        scanf("%d:%d:%d %d:%d:%d",&a1,&a2,&a3,&b1,&b2,&b3);
        int star = a1 * 60 * 60 + a2 * 60 + a3;
        int eti = b1 * 60 * 60 + b2 * 60 + b3; 
       
        st.push_back({id,star});
        etime.push_back({id,eti});
    }

    sort(st.begin(),st.end(),cmp1);
    sort(etime.begin(),etime.end(),cmp2);
    cout<<st[0].name<<" "<<etime[0].name<<endl;
    return 0;
}