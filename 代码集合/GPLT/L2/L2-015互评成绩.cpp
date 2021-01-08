#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int N,K,M;
double a[10005];
int main()
{
    cin>>N>>K>>M;
    for(int i = 0;i < N;++i){
        int ms = 0,is = 1<<30;
        for(int j = 0;j < K;++j){
            int sc;
            cin>>sc;
            a[i] += sc;
            if(ms < sc)
                ms  = sc;
            if(is > sc)
                is = sc;
        }
        a[i] = a[i] - ms - is;
        a[i] = a[i] / ((K-2)*1.0);
    }
    sort(a, a + N,[](auto &e1,auto &e2){return e1 < e2;});
    printf("%.3f",a[N-M]);
    for(int i = N - M + 1;i < N;++i){
        printf(" %.3f",a[i]);
    }

    return 0;
}
