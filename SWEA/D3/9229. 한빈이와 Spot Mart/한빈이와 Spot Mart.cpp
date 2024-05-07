#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    int t,n,m;
    cin>>t;
    for(int a = 1;a <= t;a++){
        cin>>n>>m;
        vector<int> snack(n,0);
        for(int i = 0;i < n;i++){
            cin>>snack[i];
        }
        sort(snack.begin(),snack.end());
        int start = 0,end = n-1,check = -1;
        while(start < end){
            if(snack[start]+snack[end] <= m){
                if(snack[start]+snack[end] > check){
                    check = snack[start]+snack[end];
                }
                start++;
            }
            else{
                end--;
            }
        }
        cout<<"#"<<a<<" "<<check<<endl;
    }
    return 0;
}