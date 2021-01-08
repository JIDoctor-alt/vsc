#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
//递归
struct node{
    int x1,x2;
    int h;
    bool operator<(const node & n){
        return h > n.h;
    }//从高到低排序
}Stu[10100];
int LeftTime[10100];
int RightTime[10100];
int N,MAX,X,Y;
int MinTime(int l,bool more)
{
    int h = Stu[l].h;
    int x = 0;
    int i = 0;
    if(more)
        x = Stu[l].x1;
    else 
        x = Stu[l].x2;
    //找到跳到的平台，
    for(int i = l+1;i <= N;i++)
        if(Stu[i].x1 <= x && Stu[i].x2 >= x)
            break;

    
    if(i <= N){
        if(h - Stu[i].h > MAX)
            return INF;
    }else{
        if(h > MAX)
            return INF;
        else 
            return h;
    }
        
    
    int leftTime = h - Stu[i].h + x - Stu[i].x1;
    int rightTime = h - Stu[i].h + Stu[i].x2 - x;

    if(LeftTime[i] == 0)
        LeftTime[i] = MinTime(i,true);//左边的时间
    
    if(RightTime[i] == 0)
        RightTime[i] = MinTime(i,false);

    leftTime += LeftTime[i];
    rightTime += RightTime[i];

    if(leftTime < rightTime)
        return leftTime;
    return rightTime;
}
int main()
{
    int t;
   // int N,X,Y,MAX;
    cin>>t;
    while(t--)
    {
        cin>>N>>X>>Y>>MAX;
        for(int i = 1 ;i <= N;i++)
            cin>>Stu[i].x1>>Stu[i].x2>>Stu[i].h;
        Stu[0].x1 = X;
        Stu[0].x2 = X;
        Stu[0].h = Y;
        //底层
        //Stu[N+1].x1 = -INF;
        //Stu[N+1].x2 = INF;
        //Stu[N+1].h = 0;
        sort(Stu,Stu+N+1);
        cout<<min(MinTime(0,false),MinTime(0,true))<<endl;
    }
    return 0;
}