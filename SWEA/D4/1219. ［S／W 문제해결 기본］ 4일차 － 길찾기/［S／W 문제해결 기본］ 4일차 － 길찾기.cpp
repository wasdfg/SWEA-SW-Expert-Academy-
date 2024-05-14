#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int t,n,a,b;
    for(int i = 0;i < 10;i++){
        bool pass = false;
        cin>>t>>n;
        vector<int> city[100];
        queue<int> togo;
        for(int j = 0;j < n;j++){
            cin>>a>>b;
            city[a].push_back(b);
        }
        togo.push(0);
        while(!togo.empty()){
            int x = togo.front();
            togo.pop();
            if(x == 99){
                pass = true;
                break;
            }
            for(int j = 0;j < city[x].size();j++){
                togo.push(city[x][j]);
            }
        }
        cout<<"#"<<t<<" "<<pass<<endl;
    }
    return 0;
}