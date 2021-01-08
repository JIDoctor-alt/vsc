#include<iostream>
#include<vector>

using namespace std;
vector<int> post,in,leve(51,-1);
void sovel(int prel,int inl,int postl,int n){
    if(n == 0) return;
    if(n == 1){leve[postl] = post[prel];return;}
    int root = post[prel];
    leve[postl+n-1] = root;
    int i;
    for( i = 0;i < n;i++)
    if(in[inl+i] == root)break;

    int ansl = 1,ansr = 1;
    int l = i,R = n - l - 1;
     sovel(prel+1,inl,postl,l);
     sovel(prel+l+1,inl+l+1,postl+l,R);
    
}
int main(){
    int N;
    cin>>N;
    post.resize(N);
    in.resize(N);
    for(int i = 0;i < N;i++)cin>>post[i];
    for(int i = 0;i < N;i++)cin>>in[i];
    sovel(0,0,0,N);
    for(int i = 0;i < N;i++)
    cout<<leve[i]<<endl;
    return 0;
}