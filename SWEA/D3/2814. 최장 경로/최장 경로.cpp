#include<iostream>
#include<vector>

using namespace std;

int n,m,count;
vector<int> x[11];
vector<bool> visited;

int dfs(int now,int cost){
    if(count < cost){
        count = cost;
    }
    for(int i = 0;i < x[now].size();i++){
        if(visited[x[now][i]] == 0){
            visited[x[now][i]] = 1;
            dfs(x[now][i],cost+1);
            visited[x[now][i]] = 0;
        }
    }

    return 0;
}

int main(void){
    int t,a,b,result;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n>>m;
        for(int j = 0;j < 11;j++){
            x[j].clear();
        }
        x->clear();
        visited.assign(n+1,0);
        count = 0;
        for(int j = 0;j < m;j++){
            cin>>a>>b;
            x[a].push_back(b);
            x[b].push_back(a);
        }
        for(int j = 1;j <= n;j++){
            visited[j] = 1;
            dfs(j,1);
            visited[j] = 0;
        }
        cout<<"#"<<i<<" "<<count<<endl;
    }
    return 0;
}