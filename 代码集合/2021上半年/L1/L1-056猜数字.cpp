#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    map<string,int> ms;
    int sum = 0;
    for(int i = 0;i < N;++i)
    {
        string name;
        int num;
        cin>>name>>num;
        ms[name] = num;
        sum += num;
    }
    sum  = (sum/N)/2;
    int st = 1<<30;
    string na;
    map<string,int>::iterator i;
    for(i = ms.begin();i != ms.end();++i)
    {
        if(st > abs(i->second - sum))
        {
            st = abs(i->second - sum);
            na = i->first;
        }
    }
    cout<<sum<<" "<<na<<endl;
    return 0;
}