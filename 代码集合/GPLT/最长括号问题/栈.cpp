#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0;i < s.size();++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int x =  i - st.top();
                    maxans = max(maxans,x);
                }
            }
        }
        return maxans;
    }
};