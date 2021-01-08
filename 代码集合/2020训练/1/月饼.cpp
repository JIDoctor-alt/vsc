#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    double price;
    double num;
    
    bool operator<(const node e)const
    {
        return (price/num)  > (e.price /e.num);
    }
};
vector<node> ves;
int N;
double M;
int main()
{
    cin>>N>>M;
    ves.resize(N);
    for(int i = 0;i < N;++i)
    {
        double x;
        cin>>x;
        ves[i].num = x;
    }
    for(int i = 0;i < N;++i)
    {
        double x;
        cin>>x;
        ves[i].price = x;
    }
    sort(ves.begin(),ves.end());
    double answers = 0;
    for(int i = 0;i < N;++i)
    {
        if(M - ves[i].num >= 0)
        {
            M -= ves[i].num;
            answers += ves[i].price;
        }
        else 
        {
            answers += (ves[i].price / ves[i].num) * M;
            break;
        }
    }
    printf("%.2f\n",answers);
    return 0;
}