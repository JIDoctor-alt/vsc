#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
bool isValid(string &x){
    stack<char> st;
    for(int i = 0;i < x.size();++i){
        if(x[i] == '('){
            st.push('(');
        }else if(!st.empty() && st.top() == '(')
        {
            st.pop();
        }else{
            return false;
        }
    }
    return st.empty();
}
int longestValidParentheses(string s) {
      int len = int(s.size());
      if(len < 2)
        return 0;
     int n = len;
     if(n % 2 != 0)
        n -= 1;
     for(int i  = 0; i < n; n -= 2){
         for(int j = 0;j < n - i + 1;++j){
             string x = s.substr(j ,j + i);
             if(isValid(x)){
                 return i;
             }
         }
     }
}