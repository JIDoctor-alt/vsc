#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int N,K,M;
vector<set<int> > pho;
vector<int> gender(1005);
int setGender(string& x)
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
set<int> mostIt(int fid)
{
    set<int> st;
    vector<double> f(N,0.0);
    for(auto &e : pho)
    {
        int cnt = e.size();
        if(e.count(fid))
        {
            for(auto &w : e)
            {
                if(gender[w] != gender[fid])
                {
                    f[w] += (1.0/cnt);
                }
            }
        }
    }
    double stad = *max_element(f.begin(),f.end());

    for(int i = 0;i < N;++i)
    {
        if(abs(f[i] - stad) < 1e-7)
        {
            st.insert(i);
        }
    }
    return st;
}
string Prt(int x)
{
    string ret;
    if(gender[x] == 0)
        ret += "-";
    ret += to_string(x);

    return ret;
}
int main()
{
    cin>>N>>M;
    pho.resize(M);
    for(int i = 0;i < M;++i)
    {
        cin>>K;
        while(K--)
        {
            string id;
            cin>>id;
            pho[i].insert(setGender(id));
        }
    }
    string pa,pb;
    cin>>pa>>pb;
    int a = setGender(pa), b = setGender(pb);
    auto xa = mostIt(a), xb = mostIt(b);

    if(xa.count(b)&&xb.count(a))
    {
        cout<<Prt(a)<<" "<<Prt(b)<<endl;
    }
    else 
    {
        for(auto &e : xa)
        {
            cout<<Prt(a)<<" "<<Prt(e)<<endl;
        }

        for(auto &e : xb)
        {
            cout<<Prt(b)<<" "<<Prt(e)<<endl;
        }
    }
    return 0;
}