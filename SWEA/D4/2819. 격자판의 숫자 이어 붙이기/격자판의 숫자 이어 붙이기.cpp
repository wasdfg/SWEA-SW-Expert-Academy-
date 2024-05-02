#include<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;

set<string> kind;
vector<vector<int>> pos;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};


int dfs(int x,int y,int count,string s){
    if(count == 7){
        kind.insert(s);
        return 0;
    }
    else{
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < 4 && y+dy[i] >= 0 && y+dy[i] < 4){
                dfs(x+dx[i],y+dy[i],count+1,s+to_string(pos[x][y]));
            }
        }
    }
}

int main(void){
    int t;
    cin>>t;
    for(int i = 0;i < t;i++){
        kind.clear();
        pos.assign(4,vector<int>(4,0));
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                cin>>pos[j][k];
            }
        }
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                dfs(j,k,0,"");
            }
        }
        cout<<"#"<<i+1<<" "<<kind.size()<<endl;
    }
    return 0;
}