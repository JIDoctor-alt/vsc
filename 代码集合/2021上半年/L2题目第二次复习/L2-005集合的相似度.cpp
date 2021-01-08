#include<iostream>
#include<vector>
#include<set>
#include<iomanip>
using namespace std;
int main()
{
    vector<set<int> > stu;
    int N;
    cin>>N;
    stu.resize(N+1);
    for(int i = 1;i <= N;++i)
    {
        int M;
        cin>>M;
        while(M--)
        {
            int num;
            cin>>num;
            stu[i].insert(num);
        }
    }
    int K;
    cin>>K;
    while (K--)
    {
        int a,b;
        cin>>a>>b;
        int Nc = 0,Nt = 0;
        for(auto i : stu[a])
        {
            if(stu[b].count(i) != 0)
                ++Nc;
        }
        Nt = stu[a].size() + stu[b].size() - Nc;
        cout<<fixed<<setprecision(2)<<(Nc/(Nt * 1.00) * 100)<<"%"<<endl;
    }
    return 0;
}