#include<iostream>
#include<vector>
#include<string>

using namespace std;
string Valid(string & str){
    int len = str.length();
    string ret = str;
    while(ret[0] =='0'){
        ret = ret.substr(1);
    }
    return ret;
}
int main(){
    int S,N,X;
    cin>>X;
    S = 1;
    int ans = 0;//初始为0，开始计算时再加1
  //  vector<int> result;
    string result = "";
    while (S)
    {  
        //if(S%X == 0)break;
        ans++;
        if(S/X){
           //result.push_back(S/X);
           result += to_string(S/X);
           if(S%X == 0)break;
           S = S%X;
        }else{
           // result.push_back(0);
           result += to_string(0);
        }
       // if(S%X == 0)break;
       S = S*10+1;
    }
    cout<<Valid(result)<<" "<<ans<<endl;
    return 0;
}