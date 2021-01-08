#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_V = 100005;
int d[MAX_V];
int ntr[MAX_V];
int ptr[MAX_V];
int atr[MAX_V];
int main()
{
    int htr,N,rtr;
    cin>>htr>>N;
    for(int i = 0;i < N;++i)
    {
        int address,data,next;
        cin>>address>>data>>next;
        ntr[address] = next;
        d[address] = data;
        if(next != -1)
            ptr[next] = address;
        else 
            rtr = address;
    }
    int restr = rtr;
    while(htr != rtr)
    {
        if(htr != rtr)
        {
          atr[rtr] = htr;
          rtr = ptr[rtr];
        }
        
        if(htr != rtr)
        {
            atr[htr] = rtr;
            htr = ntr[htr];  
        }
    }
    atr[htr] = -1;
    while(restr != -1)
    {
        printf("%05d %d",restr,d[restr]);
        restr = atr[restr];
        if(restr != -1)
            printf(" %05d\n",restr);
        else
            printf(" -1\n");
    }
    return 0;
}