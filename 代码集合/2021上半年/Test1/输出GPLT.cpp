#include<iostream>
#include<map>
#include<string>

using namespace std;
int ans = 0;
map<char,int> stu;
void Valid(char c){
    if(c == 'G'||c == 'g'){
         stu['G']++;
         ans++;
    }
    

    if(c == 'P'||c == 'p'){
        stu['P']++;
        ans++;
    }
        
    if(c == 'L'||c == 'l'){
        stu['L']++;
        ans++;
    }
        
    if(c == 'T'||c=='t'){
        stu['T']++;
        ans++;

    }
        
}
int main(){
    string str;
    getline(cin,str);
    int le = str.length();
    for(int i = 0;i < le;i++){
        char w = str[i];
        Valid(w);
    }
    while(ans){
        if(stu['G']){
            cout<<"G";
            stu['G']--;
            ans--;
        }
        if(stu['P']){
            cout<<"P";
            stu['P']--;
            ans--;
        }

        if(stu['L']){
            cout<<"L";
            stu['L']--;
            ans--;
        }
        if(stu['T']){
            cout<<"T";
            stu['T']--;
            ans--;
        }
    }
    return 0;
}