#include<iostream>
#include<vector>

using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
  //  vector<int> ves;
   // ves.resize(N+1);
    int ves[1100];

    int MAX_data = -1100;

    //ves = MAX_data;//哨兵
   // ves.push_back(MAX_data);
    ves[0] = MAX_data;
    int j;


    for(int i = 1;i <= N;i++){
        int we;
        cin>>we;
        int j = i;//先插入到最后
        for(;ves[j/2] > we;j/=2)
            ves[j] = ves[j/2];
        ves[j] = we;
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
            }
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