#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<regex>
using namespace std;

int main()
{
    int N;
    cin>>N;
   
    cin.get();
    while (N--)
    {
       string s;
       getline(cin,s);
       cout<<s<<endl;
       s = regex_replace(s,regex(R"(^\s*)"),"");
     
       s = regex_replace(s,regex(R"(\s*$)"),"");
     
       s = regex_replace(s,regex(R"(\s+)")," ");
       
       s = regex_replace(s,regex(R"(\s(\W))"),"$1");
    
       for(auto &c : s)
            if(c != 'I')
                c = tolower(c);
                
        s = regex_replace(s,regex(R"(\?)"),"!");
      
        s = regex_replace(s,regex(R"(\bcan you\b)"),"I_can");
        s = regex_replace(s,regex(R"(\bcould you\b)"),"I_could");
      
        s = regex_replace(s,regex(R"(\bI\b|\bme\b)"),"you");
     
        s = regex_replace(s,regex(R"(I_)"),"I ");

        cout<<"AI: "<<s<<endl;
    }
    
    return 0;
}