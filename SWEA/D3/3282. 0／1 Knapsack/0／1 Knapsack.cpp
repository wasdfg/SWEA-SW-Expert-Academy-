#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n,k;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n>>k;
        vector<int> weight(n+1,0);
        vector<int> value(n+1,0);
        vector<vector<int>> dp(101,vector<int>(1001,0));
        for(int j = 1;j <= n;j++){
            cin>>weight[j]>>value[j];
        }
        for(int a = 1;a <= n;a++){
            for(int b = 1;b <= k;b++){
                if(b >= weight[a]){
                    dp[a][b] = max(dp[a-1][b],dp[a-1][b-weight[a]]+value[a]);
                }
                else{
                    dp[a][b] = dp[a-1][b];
                }
            }
        }
        cout<<"#"<<i<<" "<<dp[n][k]<<endl;
    }
    return 0;
}