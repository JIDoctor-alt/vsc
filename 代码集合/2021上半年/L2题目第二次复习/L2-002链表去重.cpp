#include<iostream>
#include<set>
#include<cmath>
using namespace std;
const int MAX_E = 100005;
int data[MAX_E];
int ntr[MAX_E];
int wtr1[MAX_E];
int wtr2[MAX_E];
int main()
{
    int htr, N;
    cin>>htr>>N;
    for(int i = 0;i < N;++i)
    {
        int address , da,net;
        cin>>address>>da>>net;
        data[address] = da;
        ntr[address] = net;
    }
    set<int> st;
    int flag_str = htr;

    int sta_str = -1,sta_head = -1;
    int dle_str = -1 ,dle_head = -1;

    while(flag_str != -1)
    {
        int x = data[flag_str];

        if(st.count(abs(x)) == 0)
        {
            st.insert(abs(x));

            if(sta_head == -1)
            {
                 sta_head = flag_str;
                 sta_str = sta_head;
            }
            else 
            {
                wtr1[sta_str] = flag_str;
                sta_str = flag_str;
            }
            
        }
        else 
        {
            if(dle_head == -1)
            {
                dle_head = flag_str;
                dle_str = dle_head;
            }
            else 
            {
                wtr2[dle_str] = flag_str;
                dle_str = flag_str;
            }

        }
        flag_str = ntr[flag_str];
    }
    wtr1[sta_str] = -1;
    wtr2[dle_str] = -1;

    while (sta_head != -1)
    {
        //cout<<sta_head<<" "<<data[sta_head]<<" "<<wtr1[sta_head]<<endl;

        printf("%05d ",sta_head);
        printf("%d ",data[sta_head]);
        if(wtr1[sta_head] != -1)
            printf("%05d\n",wtr1[sta_head]);
        else
            printf("-1\n");
        sta_head = wtr1[sta_head];    
    }
    while (dle_head != -1)
    {
        //cout<<dle_head<<" "<<data[dle_head]<<" "<<wtr2[dle_head]<<endl;
       printf("%05d ",dle_head);
        printf("%d ",data[dle_head]);
        if(wtr2[dle_head] != -1)
            printf("%05d\n",wtr2[dle_head]);
        else
            printf("-1\n");
        dle_head = wtr2[dle_head];
    }
    
    
    return 0;
}