#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int ind;
	int costtime;
	int leaveTime;
	int time;
}Peo[1001];//1000人
queue<node> pq[21];
int N,M,K,Q;
int main()
{
	cin>>N>>M>>K>>Q;

	for(int i = 1;i <= K;++i)
	{
		cin>>Peo[i].time;

		Peo[i].ind = i;
		Peo[i].costtime = Peo[i].time;
	}

   /* for(int i = 1;i <= K;++i)
	{
		cout<<Peo[i].ind<<"=======time:"<<Peo[i].time<<endl;
	}*/



	//k个消费者 ，cnt当前进入黄线内的人数，index应该进入的人的编号
	int cnt = 1,index = 1;

	for(int i = 1;i <= 10000;++i)
	{
		//先占队
		while(cnt <= N*M && index <= K)
		{
            //窗口编号从1开始
			for(int j = 0;j < N;++j)//N个窗口
			{
              //  cout<<"Peo---------j:   "<<j<<"---------------\n";
				if(pq[j].size() < M)
				{
                    //cout<<"Peo-Peo[index]--------j:   "<<Peo[index].ind<<"---------------\n";
					pq[j].push(Peo[index]);

					++cnt;
					++index;
				}
			}
		}

      //  cout<<"========================\n";
		for(int j = 0;j < N;++j)
		{
            //如果队列是空的，会随机返回一个数，可能超过数组下标
            if(pq[j].empty())
              continue;
			int topid = pq[j].front().ind;
			Peo[topid].time--;

			if(Peo[topid].time == 0)
			{
				Peo[topid].leaveTime = i;//离开总共花费的时间
				pq[j].pop();
				--cnt;//容量加一，可以进入黄线内一个
			}
		}
	}

	for(int j = 0;j < Q;++j)
	{
		int id;
		cin>>id;
		if(Peo[id].leaveTime - Peo[id].costtime + 60*8 <  17*60)
		{
			printf("%02d:%02d\n",(Peo[id].leaveTime + 480)/60,(Peo[id].leaveTime + 480)%60);
		}
		else 
		{
			printf("Sorry\n");
		}
	}
	return 0;
}