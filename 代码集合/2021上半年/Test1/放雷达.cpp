#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
struct node{
    double s;
    double e;
    bool operator <(const node & c)const{
        if(s!= c.s)
        return s  > c.s;
        else
        {
            return e > c.e;
        }
        
    }
};

int main(){
    int n,c;//岛屿，半径 最大距离 雷达的最大范围
    int temp ;
    int ans ;
    int t = 1;
    while(cin>>n>>c &&(n || c)){
        priority_queue<node> pq;
        temp = 0;
        ans = 1;
       // if(c < 0)
         //   temp = 1;
        for(int i = 0;i < n;i++){
            double x,y;
            cin>>x>>y;
            double dis = sqrt(c*c - y*y);
            node no ;
            no.s = x - dis;
            no.e = x + dis;
            pq.push(no);
            //pq.push({x - dis,x+dis});
            if( y > c)temp = 1;
        }
        if(temp){
            cout<<"Case "<<t<<": -1"<<endl;
            t++;
            continue;//下一个测试
        }
        int firstConverd = pq.top().e;
        pq.pop();
        while(!pq.empty()){
            node v = pq.top();//头元素
            pq.pop();
            if(v.s <= firstConverd){
                firstConverd = firstConverd < v.e ? firstConverd : v.e;
            }else{
                firstConverd = v.e;
                ans++;
            }
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
        t++;
    }
    return 0;
}