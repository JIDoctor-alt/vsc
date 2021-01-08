#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    while(K--){
        stack<int> st;
        int ans = 1;
        int flag = 1;
        for(int i = 0;i < N;i++){
            int num;
            cin>>num;

            if(num == ans){
                ans++;
            }else{

                while(!st.empty()&& st.top()==ans){
                    ans++;
                    st.pop();
                }
                st.push(num);
                int n = st.size();
                if(n > M){
                    flag = 0;
                    //break;
                }
            }
        }

        
        if(flag)
            while(!st.empty()&&st.top()==ans){
                st.pop();
                ans++;
            }
        if(ans == N+1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}