#include<iostream>
#include<algorithm>
#define max_n 100005
using namespace std;
int ntr[max_n];
int data[max_n];
int ptr[max_n],res[max_n];
int n;
int main()
{
    int htr,rt;
    cin>>htr>>n;

    for(int i = 0;i < n;++i)
    {

        int a,d,ne;
        cin>>a>>d>>ne;

        data[a] = d;

        ntr[a] = ne;

        if(ne != -1){
            ptr[ne] = a;
        }else{
            rt = a;
        }
    }
    int retr = rt;
    while(rt != htr)
    {
        res[rt] = htr;
        rt = ptr[rt];

        if(rt == htr)
        {
            break;
        }
        

        res[htr] = rt;
        htr = ntr[htr]; 

    }

    res[htr] = -1;


    while(retr != -1)
    {
        
        printf("%05d %d",retr,data[retr]);
        
        retr = res[retr];

        if(retr != -1)
        {
            printf(" %05d\n",retr);
        }
        else
        {
            printf(" -1\n");
        }
    }
    return 0;
}