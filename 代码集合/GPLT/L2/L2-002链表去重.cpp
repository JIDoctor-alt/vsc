#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int data[100005];
int ntr[100005];
bool visited[100005];
int N;
int res[100005],des[100005];
int main()
{
    int htr;
    cin>>htr>>N;
    for(int i = 0;i < N;++i){
        int add,da,nt;
        cin>>add>>da>>nt;
        data[add] = da;
        ntr[add] = nt;
    }
    memset(visited,false,sizeof(visited));

    int mtr = ntr[htr];
    visited[abs(data[htr])] = true;//第一个结点不能删除
    int rtr = htr;

    int dhtr = -1,dmtr = -1;

    while(mtr != -1){

        int x = abs(data[mtr]);

        if(!visited[x]){

            res[rtr] = mtr;

            rtr = mtr;

            visited[x] = true;

        }else{

            if(dhtr == -1){

                dhtr = mtr;

                dmtr = mtr;

            }else{

                des[dmtr] = mtr;

                dmtr = mtr;

            }
        }

        mtr = ntr[mtr];
    }

    res[rtr] = -1;
    des[dmtr] = -1;

    while(htr != -1){

        printf("%05d %d",htr,data[htr]);
        htr = res[htr];
        if(htr != -1)
            printf(" %05d\n",htr);
        else 
            cout<<" -1\n";
    }
    while(dhtr != -1){

        printf("%05d %d",dhtr,data[dhtr]);
        dhtr = des[dhtr];

        if(dhtr != -1)
             printf(" %05d\n",dhtr);
        else 
            cout<<" -1\n";
    }
    return 0;
}