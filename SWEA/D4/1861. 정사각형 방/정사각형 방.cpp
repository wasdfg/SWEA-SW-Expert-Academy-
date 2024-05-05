#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> square;
vector<vector<int>> dp;
int n,count,check;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
            if(square[x+dx[i]][y+dy[i]] == square[x][y]+1){
                dp[x][y] = dp[x][y]+dfs(x+dx[i],y+dy[i]);
            }
        }
    }
    return dp[x][y];
}

int main(void){
    int t,start;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        start = 1000001;
        count = 0;
        square.assign(n,vector<int>(n,0));
        dp.assign(n,vector<int>(n,-1));
        for(int a = 0;a < n;a++){
            for(int b = 0;b < n;b++){
                cin>>square[a][b];
            }
        }
        for(int a = 0;a < n;a++){
            for(int b = 0;b < n;b++){
                int result = dfs(a,b);
                if(result > count){
                    count = result;
                    start = square[a][b];
                }
                else if(result == count){
                    start = min(start,square[a][b]);
                }
            }
        }
        cout<<"#"<<i+1<<" "<<start<<" "<<count<<endl;
    }
    return 0;
}