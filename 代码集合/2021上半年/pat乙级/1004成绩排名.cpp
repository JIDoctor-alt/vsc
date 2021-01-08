#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    string name,id;
    int score;
};
vector<edge> stu;
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string n,d;
        int s;
        cin>>n>>d>>s;
        stu.push_back({n,d,s});
    }
    sort(stu.begin(),stu.end(),[](auto &e1 , auto &e2){return e1.score < e2.score;});
    cout<<stu[N-1].name<<" "<<stu[N-1].id<<endl;
    cout<<stu[0].name<<" "<<stu[0].id<<endl;
    return 0;
}