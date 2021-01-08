#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
 
int k;
int cnt=0;
int num[100005];
 
bool cmp(int a,int b)
{
    return a>b;
}
 
int main()
{
 
    memset(num,0,sizeof(num));
    cnt=0;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        int m;
        scanf("%d",&m);
        if(m==1)
        {
            int temp;
            scanf("%d",&temp);
 
            num[++cnt]=temp;
 
            int i=cnt;
 
            while(i/2>0)
            {
                if(temp<num[i/2])
                {
                    num[i]=num[i/2];
                    i=i/2;
                }
                else
                {
                    break;
                }
            }
            num[i]=temp;
        }
        else
        {
            int minn=num[1];
            int temp=num[cnt];
            printf("%d\n",minn);
            cnt--;
            if(cnt==0)
                continue;
            int i=1;
            while(i*2<=cnt)
            {
                int a;
                if(i*2+1<=cnt&&num[i*2]>num[i*2+1]&&temp>num[i*2+1])
                {
                    a=num[i*2+1];
                    num[i]=a;
                    i=i*2+1;
                    continue;
                }
 
                if(temp>num[i*2])
                {
                    a=num[i*2];
                    num[i]=a;
                    i=i*2;
                    continue;
                }
 
                else
                {
                    break;
                }
            }
            num[i]=temp;
 
 
        }
    }
 
    return 0;
}