#include<iostream>
#include<string>

using namespace std;
int main()
{
    int N;
    cin>>N;
    cin.get();
    while(N--)
    {
        string s ;
        getline(cin,s);
        int len = s.length();
        while(true)
        {
            if(s[0] == ' ')s.erase(0);
             else break;
        }
        len  = s.length();

        while(true)
        {
            if(s[len-1] == ' ')s.erase(len-1);
            else break;
            len = s.length();
        }
        for(int i = 0;i < len;i++)
        {   if(s[i] == '?')s[i] = '!';

            if(s[i]!= 'I')s[i] = tolower(s[i]);
        }
        for(int i = 0;i < len;i++)
        {
            if(s.substr(i,7) == "can you")
                s.replace(i,7,"I can");
            else if(s.substr(i,9) == "could you")
                s.replace(i,9,"I could");
            if(s[i] == 'I' && ((i == 0) || (i > 0 && s[i-1] == ' ' && s[i+1] == ' ')))
                s.replace(i,1,"you");
            if(s.substr(i,2) == "me" && ((i > 0 &&s[i-1] == ' ') ||(i == 0)))
                s.replace(i,1,"you");

            if(!isalnum(s[i]) && (i > 0)&&s[i - 1] == ' ')s.replace(i-1,2,s[i]);
        }
        cout<<"AI: "<<s<<endl;
    }
    return 0;
}