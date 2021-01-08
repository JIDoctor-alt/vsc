#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXX 1004

using namespace std;
int x[MAXX],y[MAXX];
struct radar{
    double left,right;
};
bool cmp(radar & a,radar & b){
    return a.left < b.left;
}
int main(){
    radar node[MAXX];
    int n ,d,i,temp,t = 1,count;
    double a,high;
    while(cin>>n>>d &&(n||d)){
        temp = 0;
        count = 1;
       // if(d < 0)
           // temp = 1;
        for(int i = 0;i < n;i++){
            cin>>x[i]>>y[i];
            if(y[i] > d){//存在岛屿不再雷达范围则无解
                temp = 1;
            }
        }
        if(temp)
        {
            cout<<"Case "<<t<<": -1"<<endl;
            t++;
            continue;
        }

        for(int i  = 0;i < n;i++){
            //勾股定理求出雷达的范围
            a = sqrt(d*d - y[i]*y[i]);
            node[i].left = x[i] - a;
            node[i].right = x[i] + a;
        }
        //按照起点从小到大排序
        sort(node,node+n,cmp);
        //从第一个岛屿判断（最右边的端点作为判断条件）
        high = node[0].right;
        for(int i = 1;i < n;i++){
            //如果下一个岛屿的最左端在high的左边那么可以被前一个雷达覆盖不用在加雷达
            if(node[i].left <= high){
                //这个时候还要判断这个岛屿的范围
                //如果它的右端点在前一个右端点的前面那么这个high要更新
                high = node[i].right > high ? high : node[i].right;
            }else{
                //到该岛屿不能被上一个覆盖的时候用新的雷达
                count++;
                high = node[i].right;
            }
        }

        cout<<"Case "<<t<<": "<<count<<endl;
        t++;
    }
    return 0;
}