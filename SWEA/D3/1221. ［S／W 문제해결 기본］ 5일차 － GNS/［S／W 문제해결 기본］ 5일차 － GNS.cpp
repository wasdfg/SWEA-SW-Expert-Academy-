#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    vector<string> num = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
    int t,count;
    string a,s;
    cin>>t;
    for(int i = 1;i <= t;i++){
        vector<int> check;
        check.assign(10,0);
        cin>>a>>count;
        for(int j = 0;j < count;j++){
            cin>>s;
            for(int k = 0;k < 10;k++){
                if(s.compare(num[k]) == 0){
                    check[k]++;
                }
            }
        }
        cout<<a<<endl;
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < check[j];k++){
                cout<<num[j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}