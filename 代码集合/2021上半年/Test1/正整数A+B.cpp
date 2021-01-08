#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int cout_Valid(string s){
    //48到57 0到9
    int sum = 0;
    int les = s.length();
    for(int i = 0;i < les;i++){
        if(s[i] >= 48 && s[i] <= 57){
             sum = sum*10 + (s[i] - '0');
          
        }else
            return -1;
       
    }
    if(sum >= 1 && sum <= 1000)
        return sum;
    else
    {
        return -1;
    }
    
}
int main(){
    string str;
    getline(cin,str);
    int u = str.find(" ");//找到第一个空格的位置
    string A = str.substr(0,u);//A
    int le = str.length();
    string B = str.substr(u+1,le-u);
    int numA = cout_Valid(A);
    int numB = cout_Valid(B);
    if(numA == -1)
        cout<<"? + ";
    else
        cout<<numA<<" + ";
    
    if(numB == -1)
        cout<<"? = ";
    else
        cout<<numB<<" = ";

    if(numA!= -1 && numB != -1)
        cout<<(numA+numB)<<endl;
    else
        cout<<"?"<<endl;

    return 0;
}