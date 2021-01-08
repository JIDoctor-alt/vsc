#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pii
{
    double rate;
    char c;

    bool operator<(const pii &e)const
    {
        return rate > e.rate;
    }
};
vector<vector<pii> > t(3);
int main()
{
    int i = 0;
    while(i < 3)
    {
        double a,b,c;
        cin>>a>>b>>c;
        t[i].push_back({a,'W'});
        t[i].push_back({b,'T'});
        t[i].push_back({c,'L'});
        ++i;
    }

    for(int i = 0;i < 3;++i)
    {
        sort(t[i].begin(),t[i].end());
    }
    double ans = 1;
    for(int i = 0;i < 3;++i)
    {
        cout<<t[i][0].c<<" ";
        ans *= t[i][0].rate;
    }
    ans = (ans * 0.65 - 1) * 2;
    printf("%.2f\n",ans);
    return 0;
}