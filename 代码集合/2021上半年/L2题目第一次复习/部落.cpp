#include<iostream>
#include<set>

using namespace std;
int pre[10100];
int find(int x){
    return pre[x] == x ? x : find(pre[x]);
}
void un(int a,int b){
    int nx = find(a);
    int ny = find(b);
    if(nx > ny)pre[nx] = ny;
    else if(nx < ny)pre[ny] = nx;
}
int main(){
    int N;
    cin>>N;

    for(int i = 0;i <= 10100;i++)
        pre[i] = i;
    set<int> st;
    for(int i = 0;i < N;i++){
        int K;
        cin>>K;
        int id,t;
        cin>>t;
        st.insert(t);
        for(int j = 1;j < K;j++){
                cin>>id;
                st.insert(id);
                un(t,id);
        }
    }

    int Q;
    cin>>Q;
    int ans = 0;
    int numpeople = st.size();
    //部落的人数
    for(int i = 1;i<= numpeople;i++)
    {
        if(pre[i] == i)ans++; 
    }
    cout<<numpeople<<" "<<ans<<endl;

    for(int i = 0;i < Q;i++){
        int  wa,wb;
        cin>>wa>>wb;
        //if(find(wa)==find(wb))cout<<"Y"<<endl;
        if(pre[wa] == pre[wb])cout<<"Y"<<endl;
        else 
            cout<<"N"<<endl;

    }
    return 0;
}