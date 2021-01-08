#include<iostream>
#include<string>

using namespace std;
int main(){
    string str;
    getline(cin,str);
    int hh = (str[0] - '0')*10 + (str[1]-'0');
    int mm = (str[3]-'0')*10 + (str[4]-'0');
    if(hh < 12 ||(hh == 12 &&mm == 0)){
        cout<<"Only "<<str<<".  Too early to Dang."<<endl;
    }else{
        int count_dang = hh - 12;
        if(mm > 0)count_dang++;

        for(int i = 0;i < count_dang;i++)
            cout<<"Dang";
    }
    return 0;
}