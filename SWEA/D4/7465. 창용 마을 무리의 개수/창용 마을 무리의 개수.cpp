#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int t,n,m,a,b,count;
    cin>>t;
    for(int i = 1;i <= t;i++){
        count = 0;
        cin>>n>>m;
        vector<int> rel[n];
        vector<bool> visited(n,0);
        for(int j = 0;j < m;j++){
            cin>>a>>b;
            rel[a-1].push_back(b-1);
            rel[b-1].push_back(a-1);
        }
        for(int j = 0;j < n;j++){
            sort(rel[j].begin(),rel[j].end());
        }
        queue<int> togo;
        for(int j = 0;j < n;j++){
            if(visited[j] == 0){
                togo.push(j);
                count++;
            }
            while(!togo.empty()){
                int x = togo.front();
                togo.pop();
                visited[x] = 1;
                for(int k = 0;k < rel[x].size();k++){
                    if(visited[rel[x][k]] == 0){
                        togo.push(rel[x][k]);
                    }
                }
            }
        }
        cout<<"#"<<i<<" "<<count<<endl;
    }
    return 0;
}