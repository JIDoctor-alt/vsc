#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
int main(){
    int N;
    cin>>N;
    set<int> st;
    for(int  i = 0;i < N;i++){
        int num;
        cin>>num;
        if(st.upper_bound(num)!=st.end()){
            int j = *st.upper_bound(num);
            st.erase(j);
        }
        st.insert(num);
    }
    cout<<st.size();
    return 0;
}