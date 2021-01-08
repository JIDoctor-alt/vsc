#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int N,M,K;
map<int,int> sex;
vector<set<int> > picture;
int id_str(string x)
{
    int id = stoi(x);

    id = abs(id);

    if(x[0] == '-')
        sex[id] = 0;
    else 
        sex[id] = 1;

    return id;
}
set<int> res_judge(int x)
{

    vector<double> ans(N,0);

    for(int i = 0;i < M;++i)
    {
        set<int> pi = picture[i];

        int cnt = pi.size();

        if(pi.count(x))
        for(auto w : pi)
        {
            int id = w;

            if(sex[id] != sex[x])
            {
                ans[id] += (1/(cnt*1.0));
            }
        }
    }

    double max_ante = 0;
    set<int> ren;
    for(int i = 0;i < N;++i)
    {
        double rate = ans[i];

        if(max_ante < rate)
        {
            max_ante = rate;
            ren.clear();
            ren.insert(i);
        }else if(max_ante == rate)
        {
            ren.insert(i);
        }
    }

    return ren;
}
string prt(int x)
{
    string ret = "";
    if(sex[x] == 0)
        ret += "-";
    ret += to_string(x);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>M;
    picture.resize(M);

    for(int i = 0;i < M;++i)
    {
        cin>>K;

        while (K--)
        {

            string id;
            cin>>id;

            int w = id_str(id);

            picture[i].insert(w);
        }
    }

    string ax,bx;
    cin>>ax>>bx;

    int a = id_str(ax);
    int  b = id_str(bx);

    auto na = res_judge(abs(a));
    auto nb = res_judge(abs(b));


    if(na.count(abs(b))&&nb.count(abs(a)))
    {
        cout<<ax<<" "<<bx<<"\n";
    }
    else 
    {
        for(auto w : na)
        {
    
            cout<<ax<<" "<<prt(w)<<"\n";
        }
        for(auto w : nb)
        {

            cout<<bx<<" "<<prt(w)<<"\n";
        }
    }
    return 0;
}