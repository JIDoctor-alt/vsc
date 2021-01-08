#include<iostream>
#include<string>
#include<cstring>

using namespace std;
bool ok(string a,int i,int n){
    if(i-1 >= 0)
        return !isdigit(a[i+n])&&!isalpha(a[i+n])&&!isdigit(a[i-1])&&!isalpha(a[i-1]);
    else
    {
        return !isdigit(a[i+n])&&!isalpha(a[i+n]);
    }
   
}
int main(){
    string str;
    int N;
    cin>>N;
    getchar();
    while(N--){
        getline(cin,str);
        cout<<str<<endl;
        int m = str.length();
        //删除前面的空格
        /*for(int i = m-1;i>= 0;i--){
            if(i==m-1){
                while(str[i] ==' '){
                    str.erase(i,1);
                    i--;
                }
            }
        }*/
        while(true)
        {
            if(str[m-1] == ' ')str.erase(m-1);
            else break;
            m  = str.length();
        }
        m = str.length();
        for(int i = 0;i < m;i++){
            //删除首部的空格
            if(i == 0){
                while(str[i] == ' '){
                    str.erase(i,1);
                }
            }
            while(str[i] == ' '){
                if(!isalpha(str[i+1])&&!isdigit(str[i+1])&& i+1 < m)
                    str.erase(i,1);
                else 
                    break;
            }

            //将?改为!
            if(str[i] =='?')str[i] ='!';
            if(str[i] !='I' &&(str[i]>= 'A' && str[i]<= 'Z'))
                str[i] = str[i] + ('a' - 'A');
            m = str.length();
        }

    //    m = str.length();

        for(int i = 0;i < m;i++){
            if(str.substr(i,2) == "me"&&ok(str,i,2)&&i+1< m)
                str.replace(i,2,"you");
            else if(str.substr(i,1) == "I"&&ok(str,i,1))
                str.replace(i,1,"you");
            else if(str.substr(i,7) == "can you"&&ok(str,i,7) && i+6 < m)
                str.replace(i,7,"I can");
            else if(str.substr(i,9) == "could you" && ok(str,i,9)&&i+8 < m)
                str.replace(i,9,"I could");
            m = str.length();
        }
        cout<<"AI: ";
        cout<<str<<endl;
        
    }
    
    return 0;
}