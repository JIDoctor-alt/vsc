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
//得到编号并设置性别
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
    //异性的亲密度
    vector<double> f(N,0.0);
    //遍历照片
    
    for(auto &i : lst)
    {
        //如果存在
        if(i.count(x))
        {
            int K = i.size();
            //遍历这个照片
            for(auto &y : i)
            {
                if(gender[x] != gender[y])
                {
                    //亲密度之和
                    f[y] += 1.0/K;
                }
            }
        }
    }
    //找到最大的亲密度
    double maxI = *max_element(f.begin(),f.end());
    for(int i  = 0;i < N;++i)
    {
        if(abs(maxI - f[i]) < 1e-7)
        {
            ret.insert(i);
        }
    }
    return ret;//返回最大亲密度的集合

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
    lst.resize(N);//vector存储每个照片
    gender.resize(N);//vector存储性别

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
    string a1,b1;
    cin>>a1>>b1;

    int va = setGender(a1), vb = setGender(b1);

    auto px1 = mostInti(va);
    auto px2 = mostInti(vb);

    if(px2.count(va)&&px1.count(vb))
    {
        cout<<prt(va)<<" "<<prt(vb)<<endl;
    }
    else
    {
        for(auto &c : px1)
        {
            cout<<prt(va)<<" "<<prt(c)<<endl;
        }
        for(auto &w : px2)
        {
            cout<<prt(vb)<<" "<<prt(w)<<endl;
        }
    }
    
    return 0;

}