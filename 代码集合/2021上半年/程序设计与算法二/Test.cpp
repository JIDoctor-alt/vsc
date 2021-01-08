#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

struct plat
{
    long long x;
    long long y;
    long long h;
} plth[1001],T;//这里是保存每个板块的基本信息的。
long long N,MAX;//N个数据，MAX表示不能超过的最大高度
long long minleft[1001];//表示第i块板往左走的最小时间。也是保存状态的
long long minright[1001];//表示第i块板往右走的最小时间。也是保存状态的

long long Mintime(long long l,long long bool1)//求最小时间函数
{
    long long x,y,i;
    long long Minlefttime;
    long long Minrighttime;
    if(bool1==1)//bool1值为1，则表示往左走
    {
        x=plth[l].x;
    }
    else
        x=plth[l].y;
  y=plth[l].h;//高度，y表示高度
  for(i=l+1;i<=N;i++)//循环找出来，第l块板的左边/右边的下方是哪一个块板
  {
      if(x>=plth[i].x&&x<=plth[i].y)
        break;
  }
  if(i<=N)//如果是提前退出的，则表示第i块板是下方板
  {
      if(y-plth[i].h>MAX)//看两板之间的距离，是否大于max，如果不大于 则先不处理
         return 10000000;
  }
  else//如果下方没板了。
  {
      if(y>MAX)//看此板与下方的距离是否大于max，大于 则返回无穷大
        return 10000000;
      else//否则返回y值即可
        return y;
  }
  //上述操作后，，仍未执行return的。 是满足下方有板，且板与板之间的高度为超过max。
Minlefttime=y-plth[i].h+x-plth[i].x;//将板与板之间的高度和到达下方板左边的距离相加，即是往左边走的时间，因为是1秒一米
Minrighttime=y-plth[i].h+plth[i].y-x;//同上

if(minleft[i]==-1)//如果==-1， 则证明之前未执行过此板，现在执行
   minleft[i]=Mintime(i,1);
if(minright[i]==-1)
   minright[i]=Mintime(i,0);
Minlefttime+=minleft[i];//将minleft[i]中的值表示此板往左边时最小的时间。加上到达此板的时间。即是总时间。
Minrighttime+=minright[i];//同上
if(Minlefttime<Minrighttime)//返回往左走和往右走的两者中小的那一个。 
    return Minlefttime;
else
    return Minrighttime;


}
int main()
{
    long long t,mintime;
    long long x,h,i,j;
    while(~scanf("%lld",&t))
    {
        while(t--)
        {   memset(minleft,-1,sizeof(minleft));
            memset(minright,-1,sizeof(minright));
            scanf("%lld%lld%lld%lld",&N,&x,&h,&MAX);
            plth[0].x=x;plth[0].y=x;plth[0].h=h;
            for(i=1;i<=N;i++)
            {
                scanf("%lld%lld%lld",&plth[i].x,&plth[i].y,&plth[i].h);

            }
            for(i=0;i<N;i++)
                for(j=i;j<=N;j++)
            {
                if(plth[i].h<plth[j].h)
                {
                    T=plth[i];
                    plth[i]=plth[j];
                    plth[j]=T;
                }
            }
         mintime=Mintime(0,1);
        printf("%lld\n",mintime);

        }
    }
}
