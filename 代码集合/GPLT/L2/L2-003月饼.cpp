#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct node{
    double price;
    double weight;
};
node stu[1005];
int N;
double D;
bool cmp(node &e1,node &e2){
    return (e1.price/e1.weight) > (e2.price/e2.weight);
}
int main()
{
    cin>>N>>D;
    for(int i = 0;i < N;++i){
        cin>>stu[i].weight;
    }
    for(int i = 0;i < N;++i){
        cin>>stu[i].price;
    }
    sort(stu,stu + N,cmp);
    double res = 0;
    for(int i = 0;i < N;++i){
        if(D - stu[i].weight >= 0){
            res += stu[i].price;
            D -= stu[i].weight;
        }else{
            res += D*(stu[i].price/stu[i].weight);
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<res<<endl;
    return 0;
}