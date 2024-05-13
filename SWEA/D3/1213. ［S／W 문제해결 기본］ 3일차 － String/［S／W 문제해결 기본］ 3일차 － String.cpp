#include<iostream>
#include<string>

using namespace std;

int main(void){
    int t,count;
    for(int i = 0;i < 10;i++){
        cin>>t;
        count = 0;
        string s;
        string cmp;
        cin>>cmp;
        cin>>s;
        for(int j = 0;j < s.length();j++){
            int check = 0;
            for(int k = 0;k < cmp.length();k++){
                if(cmp[k] == s[k+j]){
                    check++;
                }
                else{
                    break;
                }
            }
            if(check == cmp.length()){
                count++;
            }
        }
        cout<<"#"<<t<<" "<<count<<endl;
    }
    return 0;
}