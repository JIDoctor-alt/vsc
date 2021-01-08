#include<iostream>
#include<stack>
#include<string>
using namespace std;
int longestValidParentheses(string s) {
      stack<int> st;
      int maxlen = 0,len = 0;
      for(int i = 0;i < s.size();++i){
          if(st.empty()){
              st.push(s[i]);
          }else{

              if(s[i] == '(')
                    st.push(s[i]);
                else{
                    char c = st.top();
                    if(c == '('){
                        st.pop();
                        ++len;
                    }else{
                        maxlen = max(len,maxlen);
                        len = 0;
                    }
                }
          }
      }  
}