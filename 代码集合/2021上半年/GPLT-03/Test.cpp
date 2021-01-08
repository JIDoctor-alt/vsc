#include<iostream>
#include<iomanip>
using namespace std;
//该结点的数值域，该结点的下一个地址，该地址的前驱地址，结果的下一个地址
int  v[100006],n[100006],p[100006],a[100006];
//-1的源码： 1000  0001  （按位取反加1）补码 1111  1111
int main()
{
    //头结点，结点数目
    int hptr,N;
    cin>>hptr>>N;
    //存取每个结点的信息
    for(int i = 0;i < N;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x] = y;//该结点的数值域
        n[x] = z;//该结点指向的下一个地址
    }
    //根据信息存储前驱结点
    int eptr = hptr;//从头结点的下一个结点（第二个结点）开始赋值它的前驱
    //j初始值为第一个结点的下一个地址（将它赋值给得个结点的前驱）
    //n[eptr] 下一个结点地址 （下一个结点的前驱为该结点的地址
    //每次赋值之后，该赋值下一个结点的前驱地址了（上一个赋值结点后移） j = n[eptr] ,
    // 前驱为 下一个了（即上一个前驱后移） eptr = n[eptr]
    //j为-1的时候 二进制按位取反（1111 1111 1111 1111） 为 0000 0000 0000 0000
    for(int j = n[eptr];~j;eptr = n[eptr],j = n[eptr])
        p[j] = eptr;
    p[hptr] = -1;//为头结点赋值它的前驱为-1
    int iptr,jptr;
    for(iptr = hptr,jptr = eptr;iptr != jptr;)
    {
        //先输出后一个
        if(iptr != jptr){
            //下一个地址为i的地址
            a[jptr] = iptr;
            //右端点左移
            jptr = p[jptr];///指向前一个结点
        }
        if(iptr != jptr)
        {
            //下一个结点地址为后面的
            a[iptr] = jptr;
            //左指针右移
            iptr = n[iptr];//下一个结点
        }
    }
    //最后地址为-1
    a[iptr] = -1;

    for(int i = eptr; ~i;i = a[i])
    {
        cout<<setw(5)<<setfill('0')<<i<<" ";
        cout<<v[i]<<" ";
        int j = a[i];
        if(~j)
            cout<<setw(5)<<setfill('0')<<j<<endl;
        else 
            cout<<"-1"<<endl;
    }
    return 0;
}