#include<iostream>
#include<string>
#include<map>
using namespace std;
using pii = pair<string,int>;
int main()
{
    map<int,pii> ms;
    int N,M;
    cin>>N;
    while (N--)
    {
        string id;
        int sj,examid;
        cin>>id>>sj>>examid;
        ms[sj] = {id,examid};
    }
    cin>>M;
    while (M--)
    {
        int id;
        cin>>id;
        cout<<ms[id].first<<" "<<ms[id].second<<endl;
    }
    return 0;
}