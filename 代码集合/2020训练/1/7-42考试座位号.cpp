#include<iostream>
#include<map>
#include<string>
using namespace std;
using pii = pair<string,int>;
map<int,pii> ms;
int N;
int main()
{
    cin>>N;
    while(N--)
    {
        string cx;
        int a,b;
        cin>>cx>>a>>b;
        ms[a].first = cx;
        ms[a].second = b;
    }
    int M;
    cin>>M;
    while(M--)
    {
        int id;
        cin>>id;
        cout<<ms[id].first<<" "<<ms[id].second<<endl;
    }
    return 0;
}