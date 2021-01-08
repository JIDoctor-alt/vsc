#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<cmath>
using namespace std;
vector<set<int> > lst;
vector<int> gender;
int N,M;
int setGender(const string &x)
{
    int ret;
    if(x[0] == '-')
    {
        ret = stoi(x.substr(1));
        gender[ret] = 0;
    }
    else 
    {
        ret = stoi(x);
        gender[ret] = 1;
    }
    return ret;
}
auto mostInti(int x)
{
    set<int> ret;
    vector<double> f(N,0.0);
    for(auto &i : lst)
    {
        if(i.count(x))
        {
            int K = i.size();
            for(auto &y : i)
            {
                if(gender[x] != gender[y])
                {
                    f[y] += 1.0/K;
                }
            }
        }
    }
    double maxI = *max_element(f.begin(),f.end());
    for(int i = 0;i < N;++i)
    {
        if(abs(maxI - f[i]) < 1e-7)
        {
            ret.insert(i);
        }
    }
    return ret;
}
string prt(int x)
{
    string ret = "";
    if(gender[x] == 0)
        ret += "-";
    ret += to_string(x);
    return ret;
}
int main()
{
    cin>>N>>M;
    lst.resize(N);
    gender.resize(N);
    for(int i = 0;i < M;++i)
    {
        int K;
        cin>>K;
        while(K--)
        {
            string x;
            cin>>x;
            lst[i].insert(setGender(x));
        }
    }
    string A,B;
    cin>>A>>B;
    int va = setGender(A),vb = setGender(B);
    auto sa = mostInti(va);
    auto sb = mostInti(vb);

    if(sa.count(vb) && sb.count(va))
    {
        cout<<prt(va)<<" "<<prt(vb)<<endl;
    }
    else
    {
        for(auto &i : sa)
        {
            cout<<prt(va)<<" "<<prt(i)<<endl;
        }
        for(auto &i : sb)
        {
            cout<<prt(vb)<<" "<<prt(i)<<endl;
        }
    }
}