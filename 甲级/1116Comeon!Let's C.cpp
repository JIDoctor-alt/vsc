#include<iostream>
#include<string>
#include<set>
#include<map>
#include<cmath>
using namespace std;
int N,K;
map<string,string> awardlist;
set<string> list;
bool isPrime(int x)
{
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    cin>>N;
    for(int i = 1;i <= N;++i)
    {
        string name;
        cin>>name;
        list.insert(name);
        awardlist[name] = "Chocolate";
        if(isPrime(i))
            awardlist[name] = "Minion";
        if(i == 1)
            awardlist[name] = "Mystery Award";
    }
    cin>>K;
    for(int i = 0;i < K;++i)
    {
        string id;
        cin>>id;
        if(!list.count(id))
        {
            cout<<id<<": "<<"Are you kidding?\n";
        }
        else 
        {
            cout<<id<<": "<<awardlist[id]<<endl;
            awardlist[id] = "Checked";
        }
    }
    return 0;
}