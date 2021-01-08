#include<iostream>

using namespace std;
int main(){
    string s;
    getline(cin,s);
    int maxvalue = 0;
    int len = s.size();
    int temp ;
    for(int i = 0;i < len;i++){
        //长度为奇数
        temp  = 1;
        for(int j = 1;j < len;j++){
            if(i - j < 0 || i + j >= len || s[i-j]!=s[i+j])
            break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp :maxvalue;
        temp = 0;
        //长度为偶数
        for(int j = 1;j < len;j++){
            if(i-j+1 < 0 || i + j >= len || s[i-j+1]!= s[i+j])
                break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp : maxvalue;
    }
    cout<<maxvalue;
    return 0;
}