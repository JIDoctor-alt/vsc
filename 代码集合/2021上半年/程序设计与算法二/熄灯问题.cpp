#include<iostream>
#include<cstring>

using namespace std;
char light[5];
char orlight[5];
char result[5];
//注意设置数值，和反转的时候 要用引用否则值不会改变
//输出格式问题
//第一行开关按下，下一行的灯的状态要随之改变，（异或操作可以用来反转）
void setBit(char& c,int index,int v)
{   
    if(v)
        c |= (1<<index);
    else
        c &=~(1<<index);
}
int getBit(char c,int index)
{
    return (c>>index)&1;
}
void FipBit(char& c,int index)
{
     c^=(1<<index);
}
void OutPrint()
{
    for(int i = 0;i < 5;i++){

         for(int j = 0;j <6;j++)
        {
            cout<<getBit(result[i],j);

            //
            if(j < 5)cout<<" ";
        }
        cout<<endl;
    }
       
}
int main(){
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 6;j++)
        {
            int num;
            cin>>num;
            setBit(light[i],j,num);
        }
    for(int n = 0;n < 64;n++)
    {
        //strcpy(orlight,light,sizeof(orlight));
        memcpy(orlight,light,sizeof(light));
        int switchs = n;
        for(int i = 0;i < 5;i++)
        {  
             result[i] = switchs;
            for(int  j = 0;j < 6;j++)
            {
                if(getBit(result[i],j)){

                    if(j > 0)FipBit(orlight[i],j-1);
                    FipBit(orlight[i],j);
                    if(j < 5)
                    FipBit(orlight[i],j+1);

                }
                
                
            }
            //下一行灯的状态
            if(i < 4)
                orlight[i+1] ^= switchs;
            //下一行开关的状态为此行灯的状态
            switchs = orlight[i];
        }
        if(orlight[4] == 0){
            OutPrint();
            break;
        }
    }
    return 0;
}