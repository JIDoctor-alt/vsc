#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int main()
{
    map<string,bool> ms;
    map<string,int> st;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string name;
        cin>>name;
        ms[name] = true;
    }
    int M;
    cin>>M;
    double sum = 0;
    for(int i = 0;i < M;++i)
    {
        string id;
        int cnt;
        cin>>id>>cnt;
        st[id] = cnt;
        sum += cnt;
    }
    sum /= M;
    vector<string> res;
    for(auto w : st)
    {
        if(w.second > sum && !ms.count(w.first))
            res.push_back(w.first);
    }
    sort(res.begin(),res.end());
    if(res.size() == 0)
    {
        cout<<"Bing Mei You"<<endl;
    }
    else 
    {
        for(auto w : res)
        {
            cout<<w<<endl;
        }
    }

    return 0;
}