#include<iostream>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int N,htr;
int ntr[100005],data[100005],rtr[100005],detr[100005];
set<int> vis;
int main()
{
    cin>>htr>>N;
    for(int i = 0;i < N;++i)
    {
        int address,num,nextaddress;
        cin>>address>>num>>nextaddress;

        data[address] = num;
        ntr[address] = nextaddress;
    }

    int movetr = ntr[htr],xtr = htr;
    int dtr = -1,mdeltr;
    vis.insert(abs(data[htr]));
    while(movetr != -1)
    {
        int da = abs(data[movetr]);

        if(!vis.count(da))
        {
            rtr[xtr] = movetr;
            xtr = movetr;
            vis.insert(da);
        }
        else
        {
            if(dtr == -1)
            {
                mdeltr = dtr = movetr;
            }
            else 
            {
                detr[mdeltr] = movetr;

                mdeltr = movetr;
            }
        }
        
        
        movetr = ntr[movetr];
    }

    rtr[xtr]  = -1;
    detr[mdeltr] = -1;

    //cout<<"---------------\n";
    while(htr != -1)
    {
        printf("%05d %d",htr,data[htr]);

        if(rtr[htr] != -1)
            printf(" %05d\n",rtr[htr]);
        else 
            printf(" -1\n");
        htr = rtr[htr];
    }

    while(dtr != -1)
    {
        printf("%05d %d",dtr,data[dtr]);
        
        if(detr[dtr] != -1)
            printf(" %05d\n",detr[dtr]);
        else 
            printf(" -1\n");
        dtr = detr[dtr];
    }

    return 0;
}