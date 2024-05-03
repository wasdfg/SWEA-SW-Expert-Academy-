#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int a,b,c,d;
    for(int i = 1;i <= 10;i++){
        int result;
        cin>>a>>b;
        vector<int> call[101];
        vector<int> depth;
        depth.assign(101,0);
        queue<int> next;
        for(int j = 0;j < a/2;j++){
            cin>>c>>d;
            bool duple = false;
            for(int t = 0;t < call[c].size();t++){
                if(call[c][t] == d){
                    duple = true;
                    break;
                }
            }
            if(duple == false){
                call[c].push_back(d);
            }
        }
        for(int t = 1;t < 101;t++){
            sort(call[t].begin(),call[t].end());
        }
        next.push(b);
        depth[b] = 1;
        while(!next.empty()){
            int x = next.front();
            next.pop();
            for(int t = 0;t < call[x].size();t++){
                if(depth[call[x][t]] == 0){
                    depth[call[x][t]] = depth[x]+1;
                    next.push(call[x][t]);
                }
            }
        }
        result = b;
        for(int t = 1;t < 101;t++){
            if(depth[result] <= depth[t]){
                result = t;
            }
        }
        cout<<"#"<<i<<" "<<result<<endl;
    }
    return 0;
}