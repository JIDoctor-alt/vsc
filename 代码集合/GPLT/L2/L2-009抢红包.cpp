#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    double price;
    int id;
    int ans;
};
node a[10005];
int N,K;
bool cmp(node &e1,node &e2){
    if(e1.price != e2.price){
        return e1.price > e2.price;
    }else {
        if(e1.ans != e2.ans){
            return e1.ans > e2.ans;
        }else{
            return e1.id < e2.id;
        }
    }
}
int main()
{
    cin>>N;
    for(int i = 1;i <= N;++i){
        cin>>K;
        a[i].id = i;
        for(int j = 0;j < K;++j){
            int id;
            double p;
            cin>>id>>p;
            a[i].price -= p;
            a[id].price += p;
            a[id].ans ++;
        }
    }
    sort(a + 1, a + N + 1,cmp);
    for(int i = 1;i <= N;++i){
        printf("%d %.2f\n",a[i].id,a[i].price*0.01);
    }

    return 0;
}