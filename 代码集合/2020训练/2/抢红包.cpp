#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct node
{
    int id;
    int acent;
    int cnt;
    bool operator<(const node& e)const
    {
        if(acent != e.acent)
        {
            return acent > e.acent;
        }
        else 
        {
            if(cnt != e.cnt)
                return cnt > e.cnt;
            else 
                return id < e.id;
        }
    }
};
int N;
vector<node> mes;
int main()
{
    cin>>N;
    mes.resize(N);
    for(int i = 1;i <= N;++i)
    {   
        int K;
        cin>>K;
        int sumPrice = 0;
        while (K--)
        {
            int fid,price;
            cin>>fid>>price;
            mes[fid - 1].cnt++;

            mes[fid - 1].acent += price;
            sumPrice += price;
        }
        mes[i - 1].id = i;
        mes[i - 1].acent -= sumPrice;
    }

    sort(mes.begin(),mes.end());
    for(auto &e : mes)
    {
        double asset = e.acent/(100 * 1.0);
        cout<<e.id<<" ";
        cout<<fixed<<setprecision(2)<<asset<<endl;
    }

    return 0;
}