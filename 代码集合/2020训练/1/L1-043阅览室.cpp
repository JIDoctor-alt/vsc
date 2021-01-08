#include<iostream>
#include<cstring>
using namespace std;
int last[1006];
char flbook[1006];
int N;
int main()
{
    cin>>N;
    while(N--)
    {
        memset(last,0,sizeof(last));
        int totalTime = 0;
        int cnt = 0;
        while(true)
        {
            int id;
            char c;
            int hh,mm;
            scanf("%d %c %d:%d",&id,&c,&hh,&mm);
            int countTime = hh * 60 + mm;

            if(id == 0)
            {
                if(cnt == 0)
                {
                    cout<<cnt<<" 0\n";
                }   
                else 
                {
                    int ans = (totalTime/(1.0 * cnt) + 0.5);
                    int testans = ans;
                    cout<<cnt<<" "<<ans<<endl;
                }
                break;
            }
            if(c == 'S')
            {
                last[id] = countTime;
                flbook[id] = c;
            }
            if(c == 'E' && flbook[id] == 'S')
            {
                totalTime += (countTime - last[id]);
                last[id] = 0;
                flbook[id] = c;
                ++cnt;
            }
        }
    }
    return 0;
}