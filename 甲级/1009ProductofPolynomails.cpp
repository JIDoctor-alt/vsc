#include<iostream>
#include<cmath>
#include<vector>

#define MAX_NUM 1000005
using namespace std;
struct node
{
    int ex;
    double ct;
};
vector<node> answer;
double c1[MAX_NUM],c2[MAX_NUM],c3[MAX_NUM];
int t1 = -1,t2 = -1;
int  numextrezero(double c[])
{
    int cnt = 0;

    for(int i = t1 + t2;i >= 0;--i)
    {
        double x = abs(c[i]);
        if(x >= 0.1)
        {
            answer.push_back({i,c[i]});
            ++cnt;
        }
    }
    return cnt;
}
int main()
{
    int k1;
    cin>>k1;
    for(int i = 0;i < k1;++i)
    {
        int et;
        double ct;
        cin>>et>>ct;

        if(t1 == -1)
            t1 = et;

        c1[et] = ct;
    }

    int k2;
    cin>>k2;
    for(int i = 0;i < k2;++i)
    {
        int et;
        double ct;
        cin>>et>>ct;

        if(t2 == -1)
            t2 = et;
        c2[et] = ct;
    }


    for(int i = t1;i >= 0;--i)
    {
        for(int j = t2;j >= 0;--j)
        {
            c3[i + j] += c1[i] * c2[j];
        }
    }

    cout<<numextrezero(c3);
    for(auto &w : answer)
    {
        printf(" %d %.1f",w.ex,w.ct);
    }
    cout<<endl;
    return 0;
}