#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int lastTime[1005];
char bookflag[1005];
int N;
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        memset(lastTime,sizeof(lastTime),0);
        int  cnt = 0;
        int totalTime = 0;
        while(true)
        {
            char c;
            int  hh,mm,id;
            scanf("%d %c %d:%d",&id,&c,&hh,&mm);

            int tim = hh * 60 + mm;
            if(id == 0)
            {
                if(cnt == 0)
                {
                    cout<<"0 0\n";
                }
                else 
                {
                    int ans = (totalTime/(1.0*cnt) + 0.5);
                    cout<<cnt<<" "<<ans<<endl;
                }

                break;
            }
            if(c == 'S')
            {
                bookflag[id] = c;
                lastTime[id] = tim;
            }
            else if(c == 'E' && bookflag[id] == 'S')
            {
                totalTime += (tim - lastTime[id]);
                bookflag[id] = c;
                ++cnt;
            }
        }
    }

    return 0;
}