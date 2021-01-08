#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;
struct edge{
    double price;
    int num;
    int id_pe;
}Tail[10001];
bool cmp(edge & a,edge & b){
    if(a.price!=b.price)
        return a.price > b.price;
    else
    {
       if(a.num!=b.num)
           return a.num > b.num;
        else
            return a.id_pe < b.id_pe;
    }
    
}
int main(){
    int N;
    cin>>N;

    //从1到N编号
    for(int i = 1;i <= N;i++){

        Tail[i].id_pe = i;//这个人的id

        //这个人发出去的红包个数K个
        int k;
        cin>>k;

        //计算发出去的红包总共多少钱

        double sum = 0;
        for(int j = 0;j < k;j++){

            int x;//请红包的人的编号
            double y;//抢到的金额（分为单位
            cin>>x>>y;


            Tail[x].num++;//该编号x 抢到的红包加1
            Tail[x].price += (y/100);//抢到的钱加（将y换成元

            sum += y;//
        }

        Tail[i].price -= (sum/100);//减去它发的红包数
    }
    sort(Tail+1,Tail+N+1,cmp);
    
    for(int i = 1;i <= N;i++){
        cout<<Tail[i].id_pe<<" "<<fixed<<setprecision(2)<<Tail[i].price<<endl;
    }

    return 0;
}