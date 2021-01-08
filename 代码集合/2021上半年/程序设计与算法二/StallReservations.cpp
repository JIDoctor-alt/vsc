#include<iostream>
#include<algorithm>
using namespace std;
struct COW
{
    int a,b;
    int no;
    bool operator < (const COW & n)const{
        return a < n.a;
    }
}cows[50100];
int pos[50100];
