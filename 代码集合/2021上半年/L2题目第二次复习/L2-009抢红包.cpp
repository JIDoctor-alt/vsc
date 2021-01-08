#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
using pii = pair<int,double>;
const int MAX_PEO = 10005;
struct node
{
    int num;
    int id;
    double price;
};
vector<node> stu;
int N;
int main()
{
    cin>>N;
    stu.resize(N+1);
    for(int i = 1;i <= N;++i)
    {
        int K;
        cin>>K;
        double sum = 0;
        while (K--)
        {
            int np,pp;
            cin>>np>>pp;
            sum += pp;
            stu[np].id = np;
            stu[np].num++;
            stu[np].price += pp;
        }
        stu[i].price -= sum;
        stu[i].id  = i;
    }
    sort(stu.begin() + 1,stu.end(),[](auto &e1,auto &e2){ if(e1.price != e2.price)return e1.price > e2.price;else {if( e1.num != e2.num){return e1.num > e2.num;}else{return e1.id < e2.id;}}});
    for(auto w : stu)
    {
        int id = w.id;
        double pr = w.price/(100.0);
        if(id == 0)
            continue;
        cout<<id<<" ";
        cout<<fixed<<setprecision(2)<<pr<<endl;
    }
    return 0;
}