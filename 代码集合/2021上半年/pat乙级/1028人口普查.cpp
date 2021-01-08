#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int ans = N;
    int minyear = 1<<30, maxyear = -1;
    string minname ,maxname;
    for(int i = 0;i < N;++i)
    {
        string name , strday;
        cin>>name>>strday;
        string year = strday.substr(0,4);
        int w =  2014 - stoi(year);
        if(w < 0 || w > 200)
        {
            --ans;
        }
        else 
        {
            if(minyear > w)
            {
                minyear = w;
                minname = name;
            }
            if(maxyear < w)
            {
                maxyear = w;
                maxname = name;
            }
        }
    }
    cout<<ans<<" "<<maxname<<" "<<minname<<endl;
    return 0;
}