#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    int time;
    int mouth,day,hour,minute;
    int status;
    bool operator<(const node &e)const 
    {
        if(name != e.name)
            return name < e.name;
        else 
            return time < e.time;
    }
};
int N;
vector<int> rate(25,0);
vector<node> records; 
double bill(node &re)
{
    double total = rate[re.hour]*re.minute + rate[24]*re.day*60;
    
    for(int i = 0;i < re.hour;++i)
    {
        total += rate[i]*60;
    }

    return total/100.0;
}
int main()
{
    for(int i = 0;i < 24;++i)
    {
        cin>>rate[i];

        rate[24] += rate[i];
    }
    cin>>N;
    records.resize(N);
 //   cout<<"--------------------------\n";
    for(int i = 0;i < N;++i)
    {
        cin>>records[i].name;

        scanf("%d:%d:%d:%d",&records[i].mouth,&records[i].day,&records[i].hour,&records[i].minute);
        //cout<<"------------------\n";
        string isOnline;
        cin>>isOnline;

        records[i].status = (isOnline == "on-line" ? 1 : 0);

        records[i].time = records[i].day*24*60 + records[i].hour*60 + records[i].minute;
     //   cout<<"=========ss========\n";
    }


   // cout<<"=============sort====\n";
    sort(records.begin(),records.end());
    map<string,vector<node> > anw;

    for(int i = 1;i < N;++i)
    {
        if(records[i].name == records[i - 1].name && records[i-1].status == 1 && records[i].status == 0)
        {
            anw[records[i-1].name].push_back(records[i-1]);
            anw[records[i].name].push_back(records[i]);
        }    
    }

    double total = 0;

    for(auto &it : anw)
    {
        
        //名字 账单月份
        cout<<it.first;
        vector<node> toll = it.second;
       /// cout<<" "<<toll[0].mouth<<endl;
        printf(" %02d\n",toll[0].mouth);
        total = 0;
        for(int i = 1;i < toll.size();i += 2)
        {
            double pert = bill(toll[i]) - bill(toll[i-1]);
            
            //打印开始和结束日期（dd:HH:mm) 持续时间（分钟） 通话费用
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",toll[i-1].day,toll[i-1].hour,toll[i-1].minute,toll[i].day,toll[i].hour,toll[i].minute,toll[i].time - toll[i-1].time,pert);
            total += pert;
        }

        printf("Total amount: $%.2f\n",total);
    }

    return 0;

}