#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
map<string,int> list;
map<string,int> mes;
struct node
{
    string name;
    bool operator<(const node& e)const
    {
        return name < e.name;
    }
};
vector<node> peo;
int main()
{
    cin>>N;
    while(N--)
    {
        string id;
        cin>>id;
        list[id] = 1;
    }
    cin>>M;
    int ans = 0;
    for(int i = 0;i < M;++i)
    {
        string fid;
        int cnt;
        cin>>fid>>cnt;
        mes[fid] = cnt;
        ans += cnt;
    }
    double ave = ans/M;
    map<string,int>::iterator i;
    for(i = mes.begin();i != mes.end();++i)
    {
        int fnum = i->second;
        string id = i->first;
        if(fnum > ave && !list.count(id))
            peo.push_back({id});
    }
    sort(peo.begin(),peo.end());
    for(auto &e : peo)
    {
        cout<<e.name<<endl;
    }
    if(peo.size() == 0)
        cout<<"Bing Mei You\n";
    return 0;
}