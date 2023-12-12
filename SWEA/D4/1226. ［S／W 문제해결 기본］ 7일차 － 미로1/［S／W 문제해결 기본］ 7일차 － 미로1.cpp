#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> maze(16,vector<int>(16,0));
queue<pair<int,int>> savepoint;
int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

int main(void){
    int N,num,c,d;
    bool goal;
    for(int i = 0;i < 10;i++){
    goal = false;
    cin>>N;
    for(int a = 0;a < 16;a++){
        for(int b = 0;b < 16;b++){
            scanf("%1d",&num);
            maze[a][b] = num;
        }
    }
    for(int a = 0;a < 16;a++){
        for(int b = 0;b < 16;b++){
            if(maze[a][b] == 1){
                continue;
            }
            if(maze[a][b] == 2){
                savepoint.push({a,b});
                break;
            }
        }
    }
    while(!savepoint.empty()){
        c = savepoint.front().first;
        d = savepoint.front().second;
        if(maze[c][d] == 3){
            goal = true;
            break;
        }
        maze[c][d] = 1;
        savepoint.pop();
        for(int t = 0;t < 4;t++){
            int a = c + x[t];
            int b = d + y[t];
            if(a < 0 || a > 15 || b < 0 || b > 15){
                continue;
            }
            if(maze[a][b] == 1){
                continue;
            }
            savepoint.push({a,b});
        }
    }
    if(goal == true){
        cout<<"#"<<N<<" 1\n";
    }
    else{
        cout<<"#"<<N<<" 0\n";
    }
    maze.resize(16,vector<int>(16,0));
    savepoint = queue<pair<int,int>>();
    }
    return 0;
}