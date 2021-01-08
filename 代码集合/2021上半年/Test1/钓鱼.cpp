#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;
const int N = 25;
int n,h;
int f[N],d[N],t[N];
//f为第一个五分钟钓鱼的鱼量
//d为每个五分钟减少的鱼量，
//t为i到i+1  五分钟的个数
int ans;
int each[N] ;//记录最终每条湖用的时间
int th,tf[N];//有效钓鱼时间和每条湖前五分钟的钓鱼量
int tans,teach[N];
int main(){
     int i,j;
     while(cin>>n&&n > 0){
         //当湖的数量为0的时候结束
         cin>>h;//输入时间
         for(i = 0;i < n;i++){
             cin>>f[i];//第一次的鱼量
         }
         for(i = 0;i < n;i++){
             cin>>d[i];//每五分钟减少的鱼量
         }
         for(i = 0; i < n-1 ;i++)
            cin>>t[i];//每个湖间距小的时间片(n-1)个
        
         h *= 12;//一小时12个时间片
         ans = -1;
         for(i = 0;i < n;i++)
         {
             //表示再第i条湖停下来
             //初始化每一次贪心
             th = h;///有效时间先初始化为总时间
             for(j = 0;j < n;j++){
                 //每条湖初始的钓鱼量初始为第一次五分钟的钓鱼量

                 tf[j] = f[j];
                 //每个湖的钓鱼时间初始化为0
                 teach[j] = 0;
             }
             tans = 0;//最大钓鱼数初始化为0
             //对每五分钟贪心选择钓鱼量最大的湖钓鱼
             while(th>0){
                 //当有效时间大于0
                 //令第一个条湖的鱼量为最大值，
                 //ind 标记湖是第几条湖
                 int ind = 0,maxs = tf[0];
                 for(j = 0;j <= i;j++){
                     //不考虑顺序先找第一鱼量最大的湖
                     if(tf[j] > maxs){
                         maxs = tf[j];
                         ind = j;
                     }
                 }
    ///最大钓鱼量为0时，将剩余的钓鱼时间加到第一个湖上的钓鱼时间
                 if(maxs == 0){
                     teach[0] += th*5;
                     break;
                 }
                 else{
                     //最大湖的钓鱼时间，每钓鱼一次加一个时间片
                     teach[ind] += 5;
                     //加上最大鱼量的湖的盖茨到玉树
                     tans += tf[ind];
                     //如果鱼量不少于减少的鱼
                     //则减去求出下一次可以钓多少鱼
                        //否则为0
                     tf[ind] = max(tf[ind]-d[ind],0);
                 }
                 th--;//有效时间减少一个时间片（一个时间片五分钟）
             }

                //i的话是表示在第i条湖停下来
             if(i != n-1)
                h -= t[i];//减去到下一条湖的时间片
            //如果值大于前面的值，就把值赋给ans
            if(tans > ans){
                ans = tans;
                for(j = 0;j < n;j++)
                    each[j] = teach[j];
            }
         }
         cout<<each[0];
         for(i = 1;i < n;i++)
            cout<<", "<<each[i];
        cout<<endl;
        cout<<"Number of fish expected: "<<ans<<endl;
    
     }
        return 0;
}