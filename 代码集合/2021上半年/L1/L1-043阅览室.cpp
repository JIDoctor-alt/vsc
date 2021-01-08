#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAX_V = 1100;
int book[MAX_V];
int lastTim[MAX_V];
int main()
{
    int N;
    cin>>N;
    
    for(int i = 0;i < N;++i)
    {
        memset(book,0,sizeof(book));
        memset(lastTim,0,sizeof(lastTim));
        int ans = 0;
    int tmep = 0;
        int hh,mm;
        while(true)
        {
            int id;
            char c;
            string str;
            cin>>id>>c>>str;
            if(id == 0)
            {
                if(ans > 0)
                {
                    cout<<ans;
                    int restime = (tmep/(1.0*ans) + 0.5);
                    cout<<" "<<restime<<endl;
                }
                else
                {
                    cout<<"0"<<" 0"<<endl;
                }

                break;
            }
            if((c == 'S')&&(book[id] == 0))
            {
                hh = stoi(str.substr(0,2));
                mm = stoi(str.substr(3,2));
                lastTim[id] = hh * 60 + mm;
                book[id] = 1;
            }
            if(c == 'E' && book[id] == 1)
            {
                ++ans;
                hh = stoi(str.substr(0,2));
                mm = stoi(str.substr(3,2));
                tmep += (hh * 60 + mm) - lastTim[id];
                lastTim[id] = 0;
                book[id] = 0;
            }
        }
    }
    return 0;
}