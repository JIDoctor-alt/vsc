#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
struct edge
{
    string n;
    int num;
    double ave;
};
int main()
{
    int N,K;
    cin>>N;
    vector<edge> ms;
    for(int i = 0;i < N;++i)
    {
        string name;
        cin>>name;
        cin>>K;
        set<int> st;
        for(int j = 0;j < K;j++)
        {
            int id;
            cin>>id;
            st.insert(id);
        }
        int num = st.size();
        double average = (1.0*K)/num;
        ms.push_back({name,num,average});
    }
    sort(ms.begin(),ms.end(),[](auto &e1,auto &e2){if(e1.num != e2.num){return e1.num > e2.num ;}else return e1.ave < e2.ave;});
    ms.push_back({"-",0,0});
    ms.push_back({"-",0,0});
    cout<<ms[0].n<<" "<<ms[1].n<<" "<<ms[2].n<<endl;
    return 0;
}