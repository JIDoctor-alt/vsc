#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n;
     int f[30];//湖的最大钓鱼量 每次钓鱼减少多少 相邻湖之间的距离
        int nf[30],dis[30];

  
        int result[30];
                int test[30];//每次测试的每个湖的钓鱼数
                  int tans ;//每次测试的最大钓鱼量
struct node{
    int idx;//湖的编号
    int numfish;//变化中的鱼量

};
bool operator < (const node & a,const node & b){
    if(a.numfish == b.numfish){
        return a.idx > b.idx;
    }else{
        return a.numfish < b.numfish;
    }
}
int main(){
    
    while(cin>>n && n){

        int timexx;
        cin>>timexx;//小时转换成时间片

        timexx *= 12;
        
        int maxresult = -1 ;


        int i;
        for(i = 0;i < n;i++)
            cin>>f[i];

        for(i = 0;i < n;i++)
            cin>>nf[i];

       // dis[0] = 0;
        for(i = 0;i < n-1;i++)
            cin>>dis[i];

        //第一个测试方案

      
        //枚举第i
        for(i = 0;i < n;i++){
            //首先计算取出走路的总时间
            memset(test,0,sizeof(test));
             tans = 0;
          //  int timexx = h;
            if(i > 0)timexx -= dis[i-1];
    

          //  for(int j = 0;j <= i;j++)
            //    timexx -= dis[i];
             //去除走路时间(从头开始枚举的所以不用循环)
        //     timexx -= dis[i];
            ///node v;
            //初始化最大路径
            priority_queue<node> pq;

            for(int j = 0;j <= i;j++){
                node xx ;
                xx.idx = j;
                xx.numfish = f[j];
                pq.push(xx);
            }
           
        //    while(timexx > 0){
            for(int j = 0;j < timexx;j++){
               node  v = pq.top();//取出最大的
                pq.pop();//出队
                
                //到这个湖的时间
                   test[v.idx] += 5;//每个湖的时间
                   tans += v.numfish;//鱼的数量佳佳
                
                  

                  v.numfish -= nf[v.idx];          //这个湖的钓鱼数减少
                  
                  //可能钓完了
                  if(v.numfish < 0)v.numfish = 0;
                 //入队  更新湖的鱼量
                  pq.push(v);
            }
          
                  
             //    timexx--;        
           // }
            //测试完成判断  取最大的量 并且结果复制到result中
            if(maxresult < tans){

                maxresult = tans;
                //重新遍历结果
                for(int j = 0;j < n;j++){
                    result[j] = test[j];
                }
            }
        }

        cout<<result[0];
        for(int d = 1;d < n;d++){
            cout<<", "<<result[d];
        }
        cout<<endl;
        cout<<"Number of fish expected: "<<maxresult<<endl;
        cout<<endl;
    }//Presentation Error


    return 0;
}