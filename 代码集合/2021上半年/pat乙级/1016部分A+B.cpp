#include<iostream>
#include<string>
using namespace std;
int main()
{
    //注意数组默认的值不是为零
    int a[10] = {0};
    int b[10] = {0};
    int A,DA,B,DB;
    cin>>A>>DA>>B>>DB;
    int index;
    while(A)
    {
        index = A%10;
        a[index]++;
        A /= 10;
    }
    while(B)
    {
        index = B%10;
        b[index]++;
        B /= 10;
    }
 //   cout<<DA<<":"<<a[DA]<<" "<<b[DB]<<endl;
    int pa;
    if(a[DA] == 0)
        pa = 0;
    else 
        pa = DA;

    for(int i = 1;i < a[DA];++i)
    {
        pa = pa * 10 + DA ; 
    }
    int pb;
    if(b[DB] == 0)
        pb = 0;
    else 
        pb = DB;
    for(int i = 1;i < b[DB];++i)
    {
        pb = pb*10 + DB;
    }
    cout<<pa+pb<<endl;
    return 0;
}