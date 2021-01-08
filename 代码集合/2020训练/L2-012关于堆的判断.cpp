#include<iostream>
#include<string>
#include<set>
using namespace std;
int N,M;
int H[1005];
void BuildHeap(int x,int index)
{
    int i = index; 
    while(H[i/2] > x)
    {
        H[i] = H[i/2];
        i /= 2;
    }
    H[i] = x;
}
int Reindex(int x)
{
    int i = 1;
    for(;i <= N;++i)
        if(H[i] == x)
            return i;

}
int main()
{
    H[0] = -10005;
    cin>>N>>M;
    
    for(int i = 0;i < N;++i)
    {
        int x;
        cin>>x;
        BuildHeap(x,i+1);
    }

   /* cout<<"===========\n";
     for(int i = 1;i <= N;++i)
    {
        cout<<H[i]<<" ";
    }*/

    for(int i = 0;i < M;++i)
    {
       int nx;
       string st2;
       cin>>nx>>st2;

       int ni = Reindex(nx);
       if(st2[0] == 'a')
       {
           
           int ny;
           string st4,st5;
           cin>>ny>>st4>>st5;
           int nj = Reindex(ny);

           cout<<(((nj / 2) == (ni / 2)) ? "T\n" : "F\n");
       }
       else 
       {
           string st3,st4;
           cin>>st3>>st4;
           if(st4 == "root")
           {
               cout<<(ni == 1 ? "T\n" : "F\n");
           }
           else 
           {
               if(st4 == "parent")
               {
                   string st5;
                   int ny;
                   cin>>st5>>ny;
                   int nj = Reindex(ny);
                 
                  cout<<(ni == (nj/2) ? "T\n" : "F\n");
               }
               else 
               {
                   string st5;
                   int ny;
                   cin>>st5>>ny;
                   int nj = Reindex(ny);

                   cout<<((ni/2) == nj ? "T\n" : "F\n");
               }
           }
       }

    }
    return 0;
}
/*
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
*/