#include<iostream>
#include<vector>
#include<set>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int N,K,M;
vector<set<int> > pho;
vector<int> gender;
int setGender(string& x)
{
    int ret ;
    //注意性别符号
    if(x[0] == '-')
    {
        ret = stoi(x.substr(1));
        //如果不截取字符串会产生负数，导致数组越界
        gender[ret] = 0;
        
    }
    else 
    {
        ret = stoi(x);
        gender[ret] = 1;
    }
    return ret;
}
set<int> mostTi(int x)
{
    set<int> st;
    //每个人的亲密度
    vector<double> f(N,0.0);

    for(int i = 0;i < M;++i)
    {
        if(pho[i].count(x))
        {
            int Kd = pho[i].size();

            for(auto &c : pho[i])
            {
                if(gender[c] != gender[x])
                {
                    f[c] += 1/(1.0*Kd);
                }
            }
        }
    }
    double maxI = *max_element(f.begin(),f.end());

    for(int i = 0;i < N;++i)
    {
        double e = f[i];
        if(abs(e - maxI) < 1e-7)
        {
            st.insert(i);
        }
    }
    return st;
}
string prT(int x)
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

    pho.resize(M);
    gender.resize(N);

    for(int i = 0;i < M;++i)
    {

        cin>>K;
        while(K--)
        {
            string x;
            cin>>x;
            pho[i].insert(setGender(x));
        }
    }

    string pa,pb;
    cin>>pa>>pb;
    int x1 = setGender(pa), x2 = setGender(pb);

    auto phx = mostTi(x1);
    auto phy = mostTi(x2);

    if(phx.count(x2) && phy.count(x1))
    {
        cout<<prT(x1)<<" "<<prT(x2)<<endl;
    }
    else 
    {
        for(auto &c : phx)
        {
            cout<<prT(x1)<<" "<<prT(c)<<endl;
        }
        for(auto &c : phy)
        {
            cout<<prT(x2)<<" "<<prT(c)<<endl;
        }
    }
    return 0;
}