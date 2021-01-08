#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define EPS 1e-7
using namespace std;
struct node{
    string name;
    double num;
    double ave;
};
bool cmp(node & a,node & b)
{
    if(a.num != b.num)
        return a.num - b.num > EPS;
    else 
        return a.ave - b.ave < EPS;
}
int main()
{
    int N;
    cin>>N;
    vector<node> peo;
    while(N--)
    {
        string name;
        cin>>name;
        int K;
        cin>>K;
        set<int> stu;
        while(K--)
        {
            int id;
            cin>>id;
            stu.insert(id);
        }
        double idnumber = stu.size();
        peo.push_back({name,idnumber,K/idnumber});
    }
    sort(peo.begin(),peo.end(),cmp);
    int len = peo.size();
    cout<<peo[0].name;
    if(len < 3){
        for(int i = 1;i < len;i++)
            cout<<" "<<peo[i].name;
        for(int i = len;i < 3;i++)
            cout<<" -";
    }
    else
    {
        for(int i = 1;i < 3;i++)
            cout<<" "<<peo[i].name;
    }

    
    
    return 0;
}