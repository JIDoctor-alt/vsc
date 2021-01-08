#include<iostream>
using namespace std;
int a[100005];
bool visited[100005];
int N,K,M;
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i){
        cin>>K;
        for(int j = 0;j < K;++j){
            int id;
            cin>>id;
            if(a[id] < K)
                     a[id] = K;
        }
    }
    cin>>M;
    int ans = 0;
    for(int i = 0;i< M;++i){
        int id;
        cin>>id;

        if(!visited[id] && a[id] <= 1){
            visited[id] = true;
            if(ans != 0)
              cout<<" ";
            printf("%05d",id);
            ++ans;
        }
    }
    if(ans == 0)
        cout<<"No one is handsome"<<endl;
    return 0;
}