#include<iostream>
#include<vector>

using namespace std;
int ves[1100];
void upAdjust(int s){
    if(s==1)return ;
    int su = ves[s];
    while (s !=1)
    {
        if(su < ves[s/2]){
            ves[s] = ves[s/2];
            s /= 2;
        }else break;
    }
    ves[s] = su;


    
}
int main(){
    int N,M;
    cin>>N>>M;
  //  vector<int> ves;
   // ves.resize(N+1);
    

    int MAX_data = -1100;

    //ves = MAX_data;//哨兵
   // ves.push_back(MAX_data);
    ves[0] = MAX_data;
    int j;


    for(int i = 1;i <= N;i++){
        int we;
        cin>>we;
        ves[i] = we;
        upAdjust(i);
        
    }
   


    for(int i = 0;i  < M;i++){
        int fist_num;
        string str;
        cin>>fist_num>>str;

       // int le = N+1;
        int j ;
        //查找1的下标
        for( j = 1;j <=  N;j++)
            if(ves[j] == fist_num){
                break;
            }

        if(str[0] == 'a'){
            //兄弟
            string str1,str2;
            int num2;
            cin>>num2>>str1>>str2;
           if(((j%2 ==0)&&ves[j+1] == num2)||( (j%2!=0 && ves[j-1] == num2))){
                cout<<"T"<<endl;
            }else{
                cout<<"F"<<endl;
            }/*
            int d;
            for(d = 1;d <= N;d++)
                if(ves[d] == num2)break;
            if(ves[j/2] == ves[d/2])
                cout<<"T"<<endl;
            else 
                cout<<"F"<<endl;*/
        }else{
            //根接待
            string str1,str2;
            cin>>str1>>str2;
            if(str2[0] == 'r'){
                if(ves[j/2] == -1)
                    cout<<"T"<<endl;
                else
                {
                    cout<<"F"<<endl;
                }
                //儿子
            }else if(str2[0] == 'p')
            {  string ss;int num2;
                cin>>ss>>num2;
                //左二子和右儿子
                if(ves[j*2] == num2 || ves[j*2+1] == num2)
                    cout<<"T"<<endl;
                else
                {
                    cout<<"F"<<endl;
                }
                /*
                int d;
                for(d = 1;d <= N;d++)
                    if(ves[d] == num2)break;
                if(ves[d/2] ==fist_num)
                    cout<<"T"<<endl;
                else 
                    cout<<"F"<<endl;*/
                
            }else if(str2[0] == 'c'){
                string st;int num2;
                cin>>st>>num2;
                //父亲
                if(ves[j/2] == num2 )
                    cout<<"T"<<endl;
                else
                {
                    cout<<"F"<<endl;
                }
                
            }
        }
        

    }
    return 0;
}