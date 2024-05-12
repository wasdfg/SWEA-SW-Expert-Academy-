#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int t,result;
    cin>>t;
    for(int i = 0;i < t;i++){
        string s;
        result = 0;
        cin>>s;
        if(s[0] == '1'){
            result++;
        }
        for(int j = 0;j < s.length()-1;j++){
            if(s[j] != s[j+1]){
                result++;
            }
        }
        cout<<"#"<<i+1<<" "<<result<<endl;
    }
    return 0;
}