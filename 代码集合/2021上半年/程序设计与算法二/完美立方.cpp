#include<iostream>

using namespace std;
int main(){
    int a,b,c,d;
    int N;
    cin>>N;
    for(int a = 2;a <= N;a++)
    {
        for(int b = 2;b <= N;b++)
        {
            for(int c = b;c <= N;c++)
            {
                for(int d = c;d <= N;d++)
                {
                    if((a*a*a)==(b*b*b+c*c*c+d*d*d))
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                }
            }
        }
    }
    return 0;
}