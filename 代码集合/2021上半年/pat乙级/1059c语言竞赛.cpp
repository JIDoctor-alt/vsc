#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
using pii = pair<string,int>;
pii stu[10005];
int vs[10005];
bool judge(int x)
{
    if(x == 1)
    {
        return true;
    }
    for(int i = 2;i <= sqrt(x);++i)
    {
        if( x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int N;
    cin>>N;
    for(int i = 1;i <= N;++i)
    {
        int id;
        cin>>id;
        vs[id] = 4;
        if(i != 1)
        {
            if(judge(i))
            {
                   stu[id].first = "Minion"; 
            }
            else 
            {
                stu[id].first = "Chocolate";
            }
        }
        else 
        {
             stu[id].first = "Mystery Award";
        }


        stu[id].second = 1;
    }
    int K;
    cin>>K;
    for(int i = 0;i < K;++i)
    {
        int id;
        cin>>id;
        //cout<<id<<": ";
        printf("%04d: ",id);
        if(vs[id] == 4)
        {
            int flag = stu[id].second;
            if(flag == 1)
            {
                cout<<stu[id].first<<endl;
                stu[id].second = 0;
            }
            else 
            {
                cout<<"Checked"<<endl;
            }
        }
        else 
        {
            cout<<"Are you kidding?"<<endl;
        }
    }
    return 0;
}