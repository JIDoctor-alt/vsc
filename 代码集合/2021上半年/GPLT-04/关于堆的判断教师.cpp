#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int h[1010];
int N,M;
void pushHeap(int x,int i)
{
    h[i] = x;
    while(i != 1)
    {
        int pai = i / 2;
        if(h[i] < h[pai])
            swap(h[i],h[pai]);
        else 
            break;
        i = pai;
    }
}
//返回该数的下标
int findIdx(int x)
{
    for(int i = 1;i <= N;++i)
        if(h[i] == x)
            return i;
}
int main()
{
    cin>>N>>M;
    for(int i = 1;i <= N;++i)
    {
        int x;
        cin>>x;
        pushHeap(x,i);
    }
    while (M--)
    {
        //第一个是数字
        int x;
        cin>>x;
        //第二个是单词
        string strt;
        cin>>strt;
        //如果第二个单词是and
        if(strt == "and")//x and y are siblings：x和y是兄弟结点；
        {
            int y;
            cin>>y;
            //将后面的两个单词读入
            cin>>strt>>strt;
            //看两个数的下标
            int idxX = findIdx(x),idxY = findIdx(y);
            //两个数下标不相等，父结点相等
            if(idxX != idxY && idxX / 2 == idxY / 2)
                cout<<"T"<<endl;
            else    
                cout<<"F"<<endl;
        }
        else 
        {
            cin>>strt;
            if(strt == "a")//x is a child of y：x是y的一个子结点。
            {
                //读走后面的两个单词
                cin>>strt>>strt;   
                int  y;
                cin>>y;
                int idxX = findIdx(x), idxY = findIdx(y);
                //判断idxX的父结点下标 
                if(idxX / 2 == idxY)
                    cout<<"T"<<endl;
                else 
                    cout<<"F"<<endl;
            }
            else
            {
                cin>>strt;
                if(strt == "parent")//x is the parent of y：x是y的父结点；
                {
                    cin>>strt;
                    int y;
                    cin>>y;
                    int idxX = findIdx(x),idxY = findIdx(y);
                    if(idxY / 2 == idxX)
                        cout<<"T"<<endl;
                    else 
                        cout<<"F"<<endl;
                }
                else 
                {
                    if(x == h[1])//x is the root：x是根结点；
                        cout<<"T"<<endl;
                    else 
                        cout<<"F"<<endl;

                }
            }
            
        }

    }
    return 0;
}