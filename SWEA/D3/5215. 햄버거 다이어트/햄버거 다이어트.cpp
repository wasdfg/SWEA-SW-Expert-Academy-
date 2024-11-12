#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n,l;
    vector<vector<int>> dp;
    vector<vector<int>> ham;
    cin>>t;
    for(int a = 0;a < t;a++){
        cin>>n>>l;
        ham.assign(n+1,vector<int>(2,0));
        dp.assign(n+1,vector<int>(l+1,0));
        for(int b = 1;b < n+1;b++){
            cin>>ham[b][0]>>ham[b][1];
        }
        for(int i = 1;i < n+1;i++){
            for(int j = 1;j < l+1;j++){
                if(j < ham[i][1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-ham[i][1]]+ham[i][0]);
                }
            }
        }
        cout<<"#"<<a+1<<" "<<dp[n][l]<<endl;
    }
}