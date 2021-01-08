#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    double cnt;
};

int main()
{
    map<string,int> peo;
    int n;
    cin>>n;

    for(int i = 0;i < n;++i)
    {
        string s;
        cin>>s;
        peo[s] = 1;
    }
    int m;
    cin>>m;
    
    vector<node> stu;
    double praise = 0,totalpeo = m;
    while(m--)
    {
        string name;
        double x;

        cin>>name>>x;
        stu.push_back({name,x});
        praise += x;
    }
    
    double average = praise / totalpeo;
    vector<string> answer;
    for(auto w : stu)
    {
        string id  = w.name;
        double nu = w.cnt;
        if(peo[id] != 1 && nu > average)
        {
            answer.push_back(id);
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size() == 0)
    {
        cout<<"Bing Mei You"<<endl;
    }
    else
    {
        for(auto &e : answer)
        {
            cout<<e<<endl;
        }
    }
    

    return 0;
}