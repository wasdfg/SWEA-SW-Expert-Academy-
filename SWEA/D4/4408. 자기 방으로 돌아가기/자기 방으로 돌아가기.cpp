#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int t,n,a,b;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        vector<int> room(401,0);
        for(int j = 0;j < n;j++){
            cin>>a>>b;
            if(a > b){
                swap(a,b);
            }
            int c = a%2==0?a-1:a;
            int d = b%2==0?b:b+1;
            for(int k = c;k <= d;k++){
                room[k]++;
            }
        }
        cout<<"#"<<i<<" "<<*max_element(room.begin(),room.end())<<endl;
    }
    return 0;
}