#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double c1[1005],c2[1005];
int t1,t2;
void sovle(double a1[],double a2[]){
    int x = t1,y = t2;
    if(x < y)
        swap(x,y);
    int ans = 0;
    for(int i = x;i >= 0;--i){
        a1[i] += a2[i];
        if(abs(a1[i]) >= 0.1)
            ++ans;
    }
    cout<<ans;
    for(int i = x;i >= 0;--i){
        if(abs(a1[i]) >= 0.1)
            printf(" %d %.1f",i,a1[i]);
    }


}
int main()
{
    int k;
    cin>>k;
     t1 = 0,t2 = 0;
    for(int i = 0;i < k;++i){
        int e;
        double c;
        cin>>e>>c;
        if(t1 == 0)
            t1 = e;
        c1[e] = c;
    }
    cin>>k;
    for(int i = 0;i < k;++i){
        int e;
        double c;
        cin>>e>>c;
        if(t2 == 0)
            t2 = e;
        c2[e] = c;
    }
    if(t1 < t2)
        sovle(c2,c1);
    else
    {
        sovle(c1,c2);
    }
    
    return 0;
}