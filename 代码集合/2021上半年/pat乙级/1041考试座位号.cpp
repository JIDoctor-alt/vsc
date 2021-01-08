#include<iostream>
#include<string>
#include<map>
using namespace std;
using pii = pair<string,int>;
int main()
{
    map<int,pii> ms;
    int N;
    cin>>N;
    while(N--)
    {
        int e1,e2;
        string str;
        cin>>str>>e1>>e2;
        ms[e1] = make_pair(str,e2);
    }
    int M;
    cin>>M;
    while(M--)
    {
        int num;
        cin>>num;
        cout<<ms[num].first<<" "<<ms[num].second<<endl;
    }
    return 0;
}