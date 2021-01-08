#include<iostream>
#include<vector>

using namespace std;
struct node{
    int address;
    int data;
    int Next;
}peo[100100];
int main()
{
    int N,s;
    cin>>s>>N;
    for(int i = 0;i < N;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        peo[a].address = a;
        peo[a].data = b;
        peo[a].Next = c;
    }
    vector<node> stu;
    while(s != -1){
        stu.push_back({peo[s].address,peo[s].data,peo[s].Next});
        s = peo[s].Next;
    }
    int i = 0,j = stu.size()-1;
    vector<node> result;
    while(true)
    {
        result.push_back({stu[j].address,stu[j].data,stu[i].address});
        j--;
        if((j+1) - (i-1) == 1)break;
        result.push_back({stu[i].address,stu[i].data,stu[j].address});
        i++;
        if((j+1) - (i-1) == 1)break;


    }
    printf("%05d %d",result[0].address,result[0].data);
    for(int k = 1;k < result.size();k++)
    {
        printf(" %05d\n%05d %d",result[k].address,result[k].address,result[k].data);
    }
    printf(" -1\n");
    return 0;
}