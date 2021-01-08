#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack> 
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=110;
const int INF=1e4;
int N,M;
struct Node{
	//vector<int> child;
	int id; 
	int length;
};
//Node graph[maxn]; 
vector<Node> Adj[maxn];
//int e[maxn]; //边上活动最早开始时间 
//int l[maxn]; //边上活动最晚开始时间
int ve[maxn];   //顶点上活动最早开始时间 
int vl[maxn];  //顶点上活动最晚开始时间
int in[maxn];  // 每个结点的入度，为0时入队
stack<int> s;
 
 
bool TopologicalSort(int N)
{
	queue<int> q;
	memset(ve,0,sizeof(ve));
	//memset(inq,0,sizeof(inq));
	/*先找出所有初始时入度为0的结点*/
	for(int i=1;i<=N;i++)  
	{
		if(in[i]==0)
		{
			q.push(i);
			//s.push(i);
			//inq[i]=true;
			//ve[i]=0; 
		}
	}
	/*每次将所有入度为0的结点入栈，拓扑序*/
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		s.push(tmp);
		//cout<<"tmp:"<<tmp<<endl;
		for(int i=0;i<Adj[tmp].size();i++)
		{
			int id=Adj[tmp][i].id;
			if(--in[id]==0) //入度减为0 加入拓扑排序 
			{
				q.push(id);
				//s.push(i);
				//inq[i]=true;
			}
			if(ve[tmp]+Adj[tmp][i].length>ve[id]) //更新ve值 
		        	ve[id]=ve[tmp]+Adj[tmp][i].length;
			
		}
	 } 
	 //cout<<"size: "<<s.size()<<endl;
	 if(s.size()==N) return true;
	 else return false;
} 
void calc_path(int N)
{
	if(TopologicalSort(N)==false)
	{
		printf("0\n");
		return ;
	}
	 /*寻找拓扑序列最后一个结点，即开始时间最晚的一个结点*/
	 int max=-1,u=-1;
	 for(int i=1;i<=N;i++)
	 {
	 	if(ve[i]>max)
	   {
	    	max=ve[i];
	    	u=i;
	   } 
	 }
	  //fill(vl,vl+maxn,INF); 
	  //vl[u]=ve[u];
	  fill(vl,vl+maxn,ve[u]); 
	  printf("%d\n",ve[u]);
	  
	 /*元素逐个出栈，即为逆拓扑序列，构造vl数组*/
	 while(!s.empty())
	 {
	 	int tmp=s.top();
	 	s.pop();
	 	//int min=INF,u;
	 	for(int i=0;i<Adj[tmp].size();i++)
	 	{
	 		int id=Adj[tmp][i].id;
	 		if(vl[id]-Adj[tmp][i].length<vl[tmp])
	 		{
	 			vl[tmp]=vl[id]-Adj[tmp][i].length;
			 }
		 }
	 }
	 /*遍历邻接点每条边，计算每项活动的最早和最晚开始时间*/
	 for(int i=1;i<=N;i++)
	 {
	 	for(int j=Adj[i].size()-1;j>=0;j--)
	 	{
	 		int id=Adj[i][j].id;
	 		int e=ve[i];
	 		int l=vl[id]-Adj[i][j].length;
	 		if(e==l) printf("%d->%d\n",i,id); 
		 }
	 }
 } 
 
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int v,w,len;
		for(int i=1;i<=N;i++)
		Adj[i].clear();
		memset(in,0,sizeof(in));
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&v,&w,&len);
			Node tmp;
			tmp.id=w;
			tmp.length=len;
			Adj[v].push_back(tmp); //有向图只要添加单向边即可 
			in[w]++; 
		}
		while(!s.empty())
		s.pop();
		calc_path(N);
		//cout<<"end!!"<<endl;
	}
	return 0;

}