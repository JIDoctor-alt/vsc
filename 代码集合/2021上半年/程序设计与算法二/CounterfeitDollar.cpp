#include<iostream>
#include<cstring>

using namespace std;
char Left[3][7];
char Right[3][7];
char result[3][7];
bool Valid(char o,bool li)
{
    for(int i = 0; i < 3;i++)
    {
        char *Lf ,*Rt;

    if(li)
    {
        Lf = Left[i];
        Rt = Right[i];
    }else
    {
        Lf = Right[i];
        Rt = Left[i];
    }

    switch (result[i][0])
    {
         case 'u':if(strchr(Rt,o) == NULL)
            return false;
            break;
         case 'e':if(strchr(Rt,o) != NULL || strchr(Lf,o)!= NULL)
            return false;
            break;
      case 'd':if(strchr(Lf,o) == NULL)
            return false;
            break;
     }
    }
    
    return true;
    
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 3;j++){
            cin>>Left[j]>>Right[j]>>result[j];
        }
        for(char c = 'A' ; c <= 'L';c++){
            if(Valid(c,true)){
                cout<<c<<" is the counterfeit coin and it is light."<<endl;
            break;
            }else if(Valid(c,false)){
                cout<<c<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
        
    }
}