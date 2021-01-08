#include<iostream>
#include<queue>
using namespace std;
int post[1010];
int pq[1010];
int cnt = 0;
int flag = true;//是二叉搜索树
void getPost(int s,int e){
    if(s > e)return;
    int nu = post[s];
    int i = s+1,j = e;
    if(flag){
       
            while(post[i] < nu && i <= e)
                i++;
            while(post[j] >= nu && j > s)
                j--;
        
    }else{
        while(post[i] >= nu && i <= e)
                i++;
         while(post[j] < nu && j > s)
                j--;
    }
    if(i-j != 1)return;
    getPost(s+1,i-1);
    getPost(i,e);

    pq[cnt++] = nu;

}
int main(){
    int N;
    cin>>N;
  //  post.resize(N);
    for(int i = 0;i < N;i++)
        cin>>post[i];
  //  pq.resize(N);
    getPost(0,N-1);

    if(cnt!=N){
        flag = false;
        //pq.clear();
        cnt=0;
        getPost(0,N-1);
    }

    if(cnt==N){
        cout<<"YES"<<endl;
        cout<<pq[0];
        for(int i = 1;i < N;i++)
            cout<<" "<<pq[i];
        cout<<endl;
    }else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;

}
