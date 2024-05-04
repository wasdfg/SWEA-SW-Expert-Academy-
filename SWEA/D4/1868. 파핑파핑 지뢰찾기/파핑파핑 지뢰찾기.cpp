#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

vector<vector<char>> mine;
vector<vector<bool>> visited;
int t,n,result = 0;
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {-1,1,1,-1,-1,0,0,1};

bool check(int x,int y){
    for(int i = 0;i < 8;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
            if(mine[x+dx[i]][y+dy[i]] == '*'){
                return false;
            }
        }
    }
    return true;
}

void boom(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0 && mine[i][j] == '.' && check(i,j)){
                result++;
                queue<pair<int,int>> togo;
                togo.push({i,j});
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    visited[x][y] = 1;
                    togo.pop();
                    for(int a = 0;a < 8;a++){
                        if(x+dx[a] >= 0 && x+dx[a] < n && y+dy[a] >= 0 && y+dy[a] < n && visited[x+dx[a]][y+dy[a]] == 0 && mine[x+dx[a]][y+dy[a]] == '.'){
                            visited[x+dx[a]][y+dy[a]] = 1;
                            if(check(x+dx[a],y+dy[a])){
                                togo.push({x+dx[a],y+dy[a]});
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void){
    string s;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        mine.assign(n,vector<char>(n,0));
        visited.assign(n,vector<bool>(n,0));
        result = 0;
        for(int a = 0;a < n;a++){
            cin>>s;
            for(int b = 0;b < n;b++){
                mine[a][b] = s[b];
            }
        }
        boom();
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(visited[j][k] == 0 && mine[j][k] == '.'){
                    result++;
                }
            }
        }
        cout<<"#"<<i<<" "<<result<<endl;
    }
    return 0;
}