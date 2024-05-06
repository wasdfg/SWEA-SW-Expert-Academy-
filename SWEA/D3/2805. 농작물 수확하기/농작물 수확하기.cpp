#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n,total;
    cin>>t;
    vector<vector<int>> farm;
    for(int i = 1;i <= t;i++){
        cin>>n;
        total = 0;
        farm.assign(n,vector<int>(n,0));
        for(int a = 0;a < n;a++){
            for(int b = 0;b < n;b++){
                scanf("%1d",&farm[a][b]);
            }
        }
        for(int a = 0;a < n/2;a++){
            for(int b = n/2-a;b < n-n/2+a;b++){
                total+=farm[a][b];
            }
            for(int b = 1+a;b < n-a-1;b++){
                total+=farm[a+n/2+1][b];
            }
        }
        for(int a = 0;a < n;a++){
            total+=farm[n/2][a];
        }
        cout<<"#"<<i<<" "<<total<<endl;
    }
}