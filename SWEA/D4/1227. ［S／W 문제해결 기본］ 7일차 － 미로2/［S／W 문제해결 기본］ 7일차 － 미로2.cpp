#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int rx,ry,t;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> maze;
    vector<vector<bool>> visited;
    for(int i = 1;i < 11;i++){
        cin>>t;
        int pass = 0;
        maze.assign(100,vector<int>(100,0));
        visited.assign(100,vector<bool>(100,0));
        queue<pair<int,int>> togo;
        for(int a = 0;a < 100;a++){
            for(int b = 0;b < 100;b++){
                scanf("%1d",&maze[a][b]);
                if(maze[a][b] == 2){
                    visited[a][b] = 1;
                    togo.push({a,b});
                }
            }
        }
        while(!togo.empty()){
            int x = togo.front().first;
            int y = togo.front().second;
            togo.pop();
            visited[x][y] = 1;
            if(maze[x][y] == 3){
                pass = 1;
                break;
            }
            for(int a = 0;a < 4;a++){
                if(x+dx[a] >= 0 && x+dx[a] < 100 && y+dy[a] >= 0 && y+dy[a] < 100 && maze[x+dx[a]][y+dy[a]] != 1 && visited[x+dx[a]][y+dy[a]] == 0){
                    togo.push({x+dx[a],y+dy[a]});
                }
            }
        }
        cout<<"#"<<i<<" "<<pass<<endl;
    }
}